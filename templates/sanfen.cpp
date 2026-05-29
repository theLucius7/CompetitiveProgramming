
i64 le = (-x >= 0 ? (-x + cx - 1) / cx : -x / cx), ri = (y >= 0 ? y / cy : (y - cy + 1) / cy);
while (ri - le > 2) {
	i64 m1 = le + (ri - le) / 3, m2 = ri - (ri - le) / 3;
	if (calc(m1) < calc(m2)) {
		ri = m2;
	} else {
		le = m1;
	}
}