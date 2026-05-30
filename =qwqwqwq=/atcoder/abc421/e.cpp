    #include <iostream>
    #include <vector>
    #include <numeric>
    #include <map>
    #include <cmath>
    #include <algorithm>
    #include <iomanip>
    #include <functional>

    // 使用标准头文件，更符合 ICPC 风格
    #include <bits/stdc++.h>

    using namespace std;

    // 使用 map 数组作为动态规划表，键为保留骰子的多重集，值为最大期望得分
    map<vector<int>, double> dp[4];
    // 存储独特点数及其概率
    vector<pair<int, double>> unique_faces;
    // 预计算阶乘
    double fact[6];

    // 预计算阶乘
    void precompute_factorials(int n) {
        fact[0] = 1.0;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }
    }

    // 计算多项式系数
    double multinomial_coeff(const vector<int>& counts) {
        int n = accumulate(counts.begin(), counts.end(), 0);
        double res = fact[n];
        for (int count : counts) {
            if (count < 0) return 0.0;
            res /= fact[count];
        }
        return res;
    }

    // 核心递归求解函数，使用 std::function 避免递归类型推断问题
    std::function<double(int, vector<int>&)> solve = 
        [&](int rolls_left, vector<int>& kept_counts) {
        int dice_to_roll = 5 - accumulate(kept_counts.begin(), kept_counts.end(), 0);

        // 基本情况：没有投掷机会了，计算最终得分
        if (rolls_left == 0) {
            double max_score = 0.0;
            for (size_t i = 0; i < unique_faces.size(); ++i) {
                max_score = max(max_score, (double)kept_counts[i] * unique_faces[i].first);
            }
            return max_score;
        }

        // 记忆化搜索：如果状态已计算过，直接返回
        if (dp[rolls_left].count(kept_counts)) {
            return dp[rolls_left][kept_counts];
        }
        
        double total_expected_score = 0.0;
        
        // lambda 函数来生成所有投掷结果的多重集
        auto generate_multiset = [&](auto self, int remaining_dice, int start_idx, vector<int>& outcome_counts) -> void {
            if (remaining_dice == 0) {
                // 计算这个结果的概率
                double outcome_prob = multinomial_coeff(outcome_counts);
                for(size_t i = 0; i < unique_faces.size(); ++i) {
                    outcome_prob *= pow(unique_faces[i].second, outcome_counts[i]);
                }

                // 对于这个结果，决定保留哪些骰子来最大化下一轮的期望得分
                double max_score_for_outcome = 0.0;
                // lambda 函数来找到最优的保留策略
                auto find_max_score_for_outcome = [&](auto self_find, int val_idx, vector<int>& current_kept_counts) -> void {
                    if (val_idx == unique_faces.size()) {
                        vector<int> next_kept_counts = kept_counts;
                        for (size_t i = 0; i < unique_faces.size(); ++i) {
                            next_kept_counts[i] += current_kept_counts[i];
                        }
                        // 递归调用 dp 求解下一轮的最优期望值
                        max_score_for_outcome = max(max_score_for_outcome, solve(rolls_left - 1, next_kept_counts));
                        return;
                    }
                    
                    for (int k = 0; k <= outcome_counts[val_idx]; ++k) {
                        current_kept_counts[val_idx] = k;
                        self_find(self_find, val_idx + 1, current_kept_counts);
                    }
                };

                vector<int> current_kept_counts_temp(unique_faces.size(), 0);
                find_max_score_for_outcome(find_max_score_for_outcome, 0, current_kept_counts_temp);
                total_expected_score += max_score_for_outcome * outcome_prob;
                return;
            }

            // 递归生成多重集
            for (size_t i = start_idx; i < unique_faces.size(); ++i) {
                outcome_counts[i]++;
                self(self, remaining_dice - 1, i, outcome_counts);
                outcome_counts[i]--;
            }
        };
        
        vector<int> initial_outcome_counts(unique_faces.size(), 0);
        generate_multiset(generate_multiset, dice_to_roll, 0, initial_outcome_counts);
        
        return dp[rolls_left][kept_counts] = total_expected_score;
    };

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        // 读取输入并统计独特点数及其概率
        map<int, int> counts_map;
        for (int i = 0; i < 6; ++i) {
            int face;
            cin >> face;
            counts_map[face]++;
        }

        for (const auto& p : counts_map) {
            unique_faces.push_back({p.first, (double)p.second / 6.0});
        }
        sort(unique_faces.begin(), unique_faces.end());

        // 预处理阶乘，用于计算概率
        precompute_factorials(5);

        // 从初始状态开始求解：3 次投掷机会，保留 0 个骰子
        vector<int> initial_kept_counts(unique_faces.size(), 0);
        cout << fixed << setprecision(10) << solve(3, initial_kept_counts) << endl;

        return 0;
    }
