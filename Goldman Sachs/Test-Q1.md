## Question 1

There is flood in the country. Cities are flooded and direct path between some cities are distroyed. Cities are represented in a adjascency matrix named matrix.

1. if 2 cities i and j are still connected, then matrix[i][j] = 1.

2. if they are disconnected then matrix[i][j] = 999.

3. if i == j then matrix[i][j] = 0.

There is lack of medicine in some cities. You are given a list of requests, each request is a pair of cities. There is need to deliver medicine from src city to dest city.
where request[i] = [src, dest]

For each request you have to print the minimum number of hours to complete the request, if each directly connected cities take 1 hour to travel.