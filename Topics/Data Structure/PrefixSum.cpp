// 2D, 1 - based

Build: pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + a[i][j];
Query: pf[x2][y2] - pf[x1-1][y2] - pf[x2][y1-1] + pf[x1-1][y1-1];

// 3D, 1 - based

Build: pf[i][j][k] = pf[i-1][j][k] + pf[i][j-1][k] + pf[i][j][k-1] - pf[i-1][j-1][k] - pf[i][j-1][k-1] - pf[i-1][j][k-1] + pf[i-1][j-1][k-1] + arr[i][j][k];
Query: pf[x2][y2][z2] - pf[x1-1][y2][z2] - pf[x2][y1-1][z2]- pf[x2][y2][z1-1] + pf[x1-1][y1-1][z2] + pf[x1-1][y2][z1-1] + pf[x2][y1-1][z1-1] - pf[x1-1][y1-1][z1-1];
