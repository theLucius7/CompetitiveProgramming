#include <bits/stdc++.h>

using i64 = long long;

struct Submission {
	std::string teamname;
	char problemname;
	int nowtime;
	std::string status;
};

struct Team {
	int ac = 0, uk = 0, penalty = 0;
	std::string name;
	bool st[26] {};
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<Submission> submissions(n);
	for (int i = 0; i < n; i++) {
		std::cin >> submissions[i].teamname >> submissions[i].problemname >> submissions[i].nowtime >> submissions[i].status;
	}
	std::sort(submissions.begin(), submissions.end(), [](Submission a, Submission b) {
		return a.nowtime < b.nowtime;
	});
	
	std::unordered_map<std::string, int> id;
	int cur = 1;
	std::vector<Team> teams;
	std::vector<std::array<bool, 26>> is_ac, is_uk;
	for (int i = 0; i < n; i++) {
		if (id[submissions[i].teamname] == 0) {
			id[submissions[i].teamname] = cur++;
			teams.push_back({0, 0, 0, submissions[i].teamname});
			is_ac.push_back({});
			is_uk.push_back({});
		}

		if (submissions[i].status == "Accepted") {
			is_ac[id[submissions[i].teamname] - 1][submissions[i].problemname - 'A'] = true;
		} else if (submissions[i].status == "Unknown") {
			is_uk[id[submissions[i].teamname] - 1][submissions[i].problemname - 'A'] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		int teamid = id[submissions[i].teamname] - 1;

		if (submissions[i].status == "Accepted") {
			if (!teams[teamid].st[submissions[i].problemname - 'A']) {
				teams[teamid].ac++;
				teams[teamid].penalty += submissions[i].nowtime;
				teams[teamid].st[submissions[i].problemname - 'A'] = true;
			}
		} else if (submissions[i].status == "Rejected" && !teams[teamid].st[submissions[i].problemname - 'A'] && is_ac[teamid][submissions[i].problemname - 'A']) {
			teams[teamid].penalty += 20;
		}
	}

	int max = 0, penalty = 0x3f3f3f3f;
	for (int i = 0; i < teams.size(); i++) {
		if (teams[i].ac > max) {
			max = teams[i].ac;
			penalty = teams[i].penalty;
		} else if (teams[i].ac == max && teams[i].penalty < penalty) {
			penalty = teams[i].penalty;
		}
	}

	for (int i = 0; i < n; i++) {
		int teamid = id[submissions[i].teamname] - 1;

		if (submissions[i].status == "Rejected" && !teams[teamid].st[submissions[i].problemname - 'A'] && is_uk[teamid][submissions[i].problemname - 'A']) {
			teams[teamid].penalty += 20;
		}

		if (submissions[i].status == "Unknown") {
			if (!teams[teamid].st[submissions[i].problemname - 'A']) {
				teams[teamid].uk++;
				teams[teamid].penalty += submissions[i].nowtime;
				teams[teamid].st[submissions[i].problemname - 'A'] = true;
			}
		}
	}

	std::vector<std::string> ans;
	for (int i = 0; i < teams.size(); i++) {
		if (teams[i].ac + teams[i].uk > max || (teams[i].ac + teams[i].uk == max && teams[i].penalty <= penalty)) {
			ans.push_back(teams[i].name);
		}
	}

	std::sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}	

	return 0;
}