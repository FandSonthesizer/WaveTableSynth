uint16_t SinusLengthInt = 2048;
// sinus, 1024 byte
const int16_t PROGMEM sinusInt[] = {
0,6,13,19,25,31,38,44,50,57,63,69,75,82,88,94,
100,107,113,119,126,132,138,144,151,157,163,169,176,182,188,194,
201,207,213,219,226,232,238,244,251,257,263,269,275,282,288,294,
300,307,313,319,325,331,338,344,350,356,362,369,375,381,387,393,
399,406,412,418,424,430,436,442,449,455,461,467,473,479,485,491,
497,503,510,516,522,528,534,540,546,552,558,564,570,576,582,588,
594,600,606,612,618,624,630,636,642,648,654,660,666,672,678,684,
690,696,701,707,713,719,725,731,737,743,748,754,760,766,772,778,
783,789,795,801,807,812,818,824,830,835,841,847,852,858,864,870,
875,881,887,892,898,903,909,915,920,926,932,937,943,948,954,959,
965,970,976,982,987,993,998,1003,1009,1014,1020,1025,1031,1036,1042,1047,
1052,1058,1063,1068,1074,1079,1085,1090,1095,1100,1106,1111,1116,1122,1127,1132,
1137,1142,1148,1153,1158,1163,1168,1174,1179,1184,1189,1194,1199,1204,1209,1214,
1219,1224,1229,1234,1239,1244,1249,1254,1259,1264,1269,1274,1279,1284,1289,1294,
1299,1303,1308,1313,1318,1323,1328,1332,1337,1342,1347,1351,1356,1361,1365,1370,
1375,1379,1384,1389,1393,1398,1402,1407,1411,1416,1421,1425,1430,1434,1439,1443,
1447,1452,1456,1461,1465,1469,1474,1478,1483,1487,1491,1495,1500,1504,1508,1513,
1517,1521,1525,1529,1533,1538,1542,1546,1550,1554,1558,1562,1566,1570,1574,1578,
1582,1586,1590,1594,1598,1602,1606,1610,1614,1618,1621,1625,1629,1633,1637,1640,
1644,1648,1652,1655,1659,1663,1666,1670,1674,1677,1681,1684,1688,1691,1695,1699,
1702,1705,1709,1712,1716,1719,1723,1726,1729,1733,1736,1739,1743,1746,1749,1753,
1756,1759,1762,1765,1769,1772,1775,1778,1781,1784,1787,1790,1793,1796,1799,1802,
1805,1808,1811,1814,1817,1820,1823,1826,1828,1831,1834,1837,1840,1842,1845,1848,
1850,1853,1856,1858,1861,1864,1866,1869,1871,1874,1876,1879,1881,1884,1886,1889,
1891,1894,1896,1898,1901,1903,1905,1908,1910,1912,1914,1917,1919,1921,1923,1925,
1927,1929,1932,1934,1936,1938,1940,1942,1944,1946,1948,1950,1951,1953,1955,1957,
1959,1961,1962,1964,1966,1968,1969,1971,1973,1975,1976,1978,1979,1981,1983,1984,
1986,1987,1989,1990,1992,1993,1994,1996,1997,1999,2000,2001,2003,2004,2005,2006,
2008,2009,2010,2011,2012,2014,2015,2016,2017,2018,2019,2020,2021,2022,2023,2024,
2025,2026,2027,2028,2028,2029,2030,2031,2032,2032,2033,2034,2035,2035,2036,2037,
2037,2038,2038,2039,2039,2040,2040,2041,2041,2042,2042,2043,2043,2044,2044,2044,
2045,2045,2045,2045,2046,2046,2046,2046,2046,2047,2047,2047,2047,2047,2047,2047,
2047,2047,2047,2047,2047,2047,2047,2047,2046,2046,2046,2046,2046,2045,2045,2045,
2045,2044,2044,2044,2043,2043,2042,2042,2041,2041,2040,2040,2039,2039,2038,2038,
2037,2037,2036,2035,2035,2034,2033,2032,2032,2031,2030,2029,2028,2028,2027,2026,
2025,2024,2023,2022,2021,2020,2019,2018,2017,2016,2015,2014,2012,2011,2010,2009,
2008,2006,2005,2004,2003,2001,2000,1999,1997,1996,1994,1993,1992,1990,1989,1987,
1986,1984,1983,1981,1979,1978,1976,1975,1973,1971,1969,1968,1966,1964,1962,1961,
1959,1957,1955,1953,1951,1950,1948,1946,1944,1942,1940,1938,1936,1934,1932,1929,
1927,1925,1923,1921,1919,1917,1914,1912,1910,1908,1905,1903,1901,1898,1896,1894,
1891,1889,1886,1884,1881,1879,1876,1874,1871,1869,1866,1864,1861,1858,1856,1853,
1850,1848,1845,1842,1840,1837,1834,1831,1828,1826,1823,1820,1817,1814,1811,1808,
1805,1802,1799,1796,1793,1790,1787,1784,1781,1778,1775,1772,1769,1765,1762,1759,
1756,1753,1749,1746,1743,1739,1736,1733,1729,1726,1723,1719,1716,1712,1709,1705,
1702,1699,1695,1691,1688,1684,1681,1677,1674,1670,1666,1663,1659,1655,1652,1648,
1644,1640,1637,1633,1629,1625,1621,1618,1614,1610,1606,1602,1598,1594,1590,1586,
1582,1578,1574,1570,1566,1562,1558,1554,1550,1546,1542,1538,1533,1529,1525,1521,
1517,1513,1508,1504,1500,1495,1491,1487,1483,1478,1474,1469,1465,1461,1456,1452,
1447,1443,1439,1434,1430,1425,1421,1416,1411,1407,1402,1398,1393,1389,1384,1379,
1375,1370,1365,1361,1356,1351,1347,1342,1337,1332,1328,1323,1318,1313,1308,1303,
1299,1294,1289,1284,1279,1274,1269,1264,1259,1254,1249,1244,1239,1234,1229,1224,
1219,1214,1209,1204,1199,1194,1189,1184,1179,1174,1168,1163,1158,1153,1148,1142,
1137,1132,1127,1122,1116,1111,1106,1100,1095,1090,1085,1079,1074,1068,1063,1058,
1052,1047,1042,1036,1031,1025,1020,1014,1009,1003,998,993,987,982,976,970,
965,959,954,948,943,937,932,926,920,915,909,903,898,892,887,881,
875,870,864,858,852,847,841,835,830,824,818,812,807,801,795,789,
783,778,772,766,760,754,748,743,737,731,725,719,713,707,701,696,
690,684,678,672,666,660,654,648,642,636,630,624,618,612,606,600,
594,588,582,576,570,564,558,552,546,540,534,528,522,516,510,503,
497,491,485,479,473,467,461,455,449,442,436,430,424,418,412,406,
399,393,387,381,375,369,362,356,350,344,338,331,325,319,313,307,
300,294,288,282,275,269,263,257,251,244,238,232,226,219,213,207,
201,194,188,182,176,169,163,157,151,144,138,132,126,119,113,107,
100,94,88,82,75,69,63,57,50,44,38,31,25,19,13,6,
0,-5,-12,-18,-24,-30,-37,-43,-49,-56,-62,-68,-74,-81,-87,-93,
-99,-106,-112,-118,-125,-131,-137,-143,-150,-156,-162,-168,-175,-181,-187,-193,
-200,-206,-212,-218,-225,-231,-237,-243,-250,-256,-262,-268,-274,-281,-287,-293,
-299,-306,-312,-318,-324,-330,-337,-343,-349,-355,-361,-368,-374,-380,-386,-392,
-398,-405,-411,-417,-423,-429,-435,-441,-448,-454,-460,-466,-472,-478,-484,-490,
-496,-502,-509,-515,-521,-527,-533,-539,-545,-551,-557,-563,-569,-575,-581,-587,
-593,-599,-605,-611,-617,-623,-629,-635,-641,-647,-653,-659,-665,-671,-677,-683,
-689,-695,-700,-706,-712,-718,-724,-730,-736,-742,-747,-753,-759,-765,-771,-777,
-782,-788,-794,-800,-806,-811,-817,-823,-829,-834,-840,-846,-851,-857,-863,-869,
-874,-880,-886,-891,-897,-902,-908,-914,-919,-925,-931,-936,-942,-947,-953,-958,
-964,-969,-975,-981,-986,-992,-997,-1002,-1008,-1013,-1019,-1024,-1030,-1035,-1041,-1046,
-1051,-1057,-1062,-1067,-1073,-1078,-1084,-1089,-1094,-1099,-1105,-1110,-1115,-1121,-1126,-1131,
-1136,-1141,-1147,-1152,-1157,-1162,-1167,-1173,-1178,-1183,-1188,-1193,-1198,-1203,-1208,-1213,
-1218,-1223,-1228,-1233,-1238,-1243,-1248,-1253,-1258,-1263,-1268,-1273,-1278,-1283,-1288,-1293,
-1298,-1302,-1307,-1312,-1317,-1322,-1327,-1331,-1336,-1341,-1346,-1350,-1355,-1360,-1364,-1369,
-1374,-1378,-1383,-1388,-1392,-1397,-1401,-1406,-1410,-1415,-1420,-1424,-1429,-1433,-1438,-1442,
-1446,-1451,-1455,-1460,-1464,-1468,-1473,-1477,-1482,-1486,-1490,-1494,-1499,-1503,-1507,-1512,
-1516,-1520,-1524,-1528,-1532,-1537,-1541,-1545,-1549,-1553,-1557,-1561,-1565,-1569,-1573,-1577,
-1581,-1585,-1589,-1593,-1597,-1601,-1605,-1609,-1613,-1617,-1620,-1624,-1628,-1632,-1636,-1639,
-1643,-1647,-1651,-1654,-1658,-1662,-1665,-1669,-1673,-1676,-1680,-1683,-1687,-1690,-1694,-1698,
-1701,-1704,-1708,-1711,-1715,-1718,-1722,-1725,-1728,-1732,-1735,-1738,-1742,-1745,-1748,-1752,
-1755,-1758,-1761,-1764,-1768,-1771,-1774,-1777,-1780,-1783,-1786,-1789,-1792,-1795,-1798,-1801,
-1804,-1807,-1810,-1813,-1816,-1819,-1822,-1825,-1827,-1830,-1833,-1836,-1839,-1841,-1844,-1847,
-1849,-1852,-1855,-1857,-1860,-1863,-1865,-1868,-1870,-1873,-1875,-1878,-1880,-1883,-1885,-1888,
-1890,-1893,-1895,-1897,-1900,-1902,-1904,-1907,-1909,-1911,-1913,-1916,-1918,-1920,-1922,-1924,
-1926,-1928,-1931,-1933,-1935,-1937,-1939,-1941,-1943,-1945,-1947,-1949,-1950,-1952,-1954,-1956,
-1958,-1960,-1961,-1963,-1965,-1967,-1968,-1970,-1972,-1974,-1975,-1977,-1978,-1980,-1982,-1983,
-1985,-1986,-1988,-1989,-1991,-1992,-1993,-1995,-1996,-1998,-1999,-2000,-2002,-2003,-2004,-2005,
-2007,-2008,-2009,-2010,-2011,-2013,-2014,-2015,-2016,-2017,-2018,-2019,-2020,-2021,-2022,-2023,
-2024,-2025,-2026,-2027,-2027,-2028,-2029,-2030,-2031,-2031,-2032,-2033,-2034,-2034,-2035,-2036,
-2036,-2037,-2037,-2038,-2038,-2039,-2039,-2040,-2040,-2041,-2041,-2042,-2042,-2043,-2043,-2043,
-2044,-2044,-2044,-2044,-2045,-2045,-2045,-2045,-2045,-2046,-2046,-2046,-2046,-2046,-2046,-2046,
-2046,-2046,-2046,-2046,-2046,-2046,-2046,-2046,-2045,-2045,-2045,-2045,-2045,-2044,-2044,-2044,
-2044,-2043,-2043,-2043,-2042,-2042,-2041,-2041,-2040,-2040,-2039,-2039,-2038,-2038,-2037,-2037,
-2036,-2036,-2035,-2034,-2034,-2033,-2032,-2031,-2031,-2030,-2029,-2028,-2027,-2027,-2026,-2025,
-2024,-2023,-2022,-2021,-2020,-2019,-2018,-2017,-2016,-2015,-2014,-2013,-2011,-2010,-2009,-2008,
-2007,-2005,-2004,-2003,-2002,-2000,-1999,-1998,-1996,-1995,-1993,-1992,-1991,-1989,-1988,-1986,
-1985,-1983,-1982,-1980,-1978,-1977,-1975,-1974,-1972,-1970,-1968,-1967,-1965,-1963,-1961,-1960,
-1958,-1956,-1954,-1952,-1950,-1949,-1947,-1945,-1943,-1941,-1939,-1937,-1935,-1933,-1931,-1928,
-1926,-1924,-1922,-1920,-1918,-1916,-1913,-1911,-1909,-1907,-1904,-1902,-1900,-1897,-1895,-1893,
-1890,-1888,-1885,-1883,-1880,-1878,-1875,-1873,-1870,-1868,-1865,-1863,-1860,-1857,-1855,-1852,
-1849,-1847,-1844,-1841,-1839,-1836,-1833,-1830,-1827,-1825,-1822,-1819,-1816,-1813,-1810,-1807,
-1804,-1801,-1798,-1795,-1792,-1789,-1786,-1783,-1780,-1777,-1774,-1771,-1768,-1764,-1761,-1758,
-1755,-1752,-1748,-1745,-1742,-1738,-1735,-1732,-1728,-1725,-1722,-1718,-1715,-1711,-1708,-1704,
-1701,-1698,-1694,-1690,-1687,-1683,-1680,-1676,-1673,-1669,-1665,-1662,-1658,-1654,-1651,-1647,
-1643,-1639,-1636,-1632,-1628,-1624,-1620,-1617,-1613,-1609,-1605,-1601,-1597,-1593,-1589,-1585,
-1581,-1577,-1573,-1569,-1565,-1561,-1557,-1553,-1549,-1545,-1541,-1537,-1532,-1528,-1524,-1520,
-1516,-1512,-1507,-1503,-1499,-1494,-1490,-1486,-1482,-1477,-1473,-1468,-1464,-1460,-1455,-1451,
-1446,-1442,-1438,-1433,-1429,-1424,-1420,-1415,-1410,-1406,-1401,-1397,-1392,-1388,-1383,-1378,
-1374,-1369,-1364,-1360,-1355,-1350,-1346,-1341,-1336,-1331,-1327,-1322,-1317,-1312,-1307,-1302,
-1298,-1293,-1288,-1283,-1278,-1273,-1268,-1263,-1258,-1253,-1248,-1243,-1238,-1233,-1228,-1223,
-1218,-1213,-1208,-1203,-1198,-1193,-1188,-1183,-1178,-1173,-1167,-1162,-1157,-1152,-1147,-1141,
-1136,-1131,-1126,-1121,-1115,-1110,-1105,-1099,-1094,-1089,-1084,-1078,-1073,-1067,-1062,-1057,
-1051,-1046,-1041,-1035,-1030,-1024,-1019,-1013,-1008,-1002,-997,-992,-986,-981,-975,-969,
-964,-958,-953,-947,-942,-936,-931,-925,-919,-914,-908,-902,-897,-891,-886,-880,
-874,-869,-863,-857,-851,-846,-840,-834,-829,-823,-817,-811,-806,-800,-794,-788,
-782,-777,-771,-765,-759,-753,-747,-742,-736,-730,-724,-718,-712,-706,-700,-695,
-689,-683,-677,-671,-665,-659,-653,-647,-641,-635,-629,-623,-617,-611,-605,-599,
-593,-587,-581,-575,-569,-563,-557,-551,-545,-539,-533,-527,-521,-515,-509,-502,
-496,-490,-484,-478,-472,-466,-460,-454,-448,-441,-435,-429,-423,-417,-411,-405,
-398,-392,-386,-380,-374,-368,-361,-355,-349,-343,-337,-330,-324,-318,-312,-306,
-299,-293,-287,-281,-274,-268,-262,-256,-250,-243,-237,-231,-225,-218,-212,-206,
-200,-193,-187,-181,-175,-168,-162,-156,-150,-143,-137,-131,-125,-118,-112,-106,
-99,-93,-87,-81,-74,-68,-62,-56,-49,-43,-37,-30,-24,-18,-12,-5
};

int16_t getSinInt(uint16_t index) {
  return pgm_read_word( &sinusInt[index] );
}

