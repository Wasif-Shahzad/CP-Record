cmake_minimum_required(VERSION 4.0)
project(CP)

set(CMAKE_CXX_STANDARD 20)

add_executable(CP main.cpp
        CSES/dp/counting_numbers.cpp
        CSES/dp/increasing_subsequence_2.cpp
        CSES/dp/edit_distance.cpp
        "AtCoder Beginner Contests/419/a.cpp"
        "AtCoder Beginner Contests/419/b.cpp"
        "AtCoder Beginner Contests/419/c.cpp"
        "AtCoder Beginner Contests/419/d.cpp"
        "AtCoder Beginner Contests/419/e.cpp"
        StressTest/Gen.cpp
        StressTest/Sol.cpp
        StressTest/Brute.cpp
        CSES/dp/elevator_rides.cpp
        "Atcoder DP Contest/u_grouping.cpp"
        "CF Archive/1969D.cpp"
        "CodeChef Starters/200 Div2/a.cpp"
        "CodeChef Starters/200 Div2/b.cpp"
        "CodeChef Starters/200 Div2/c.cpp"
        "CodeChef Starters/200 Div2/d.cpp"
        "CF Archive/2B.cpp"
        "Codeforces Contests/Round 1043 (Div 3)/F.cpp"
        "Codeforces Contests/Round 1043 (Div 3)/A.cpp"
        "Codeforces Contests/Round 1043 (Div 3)/B.cpp"
        "Codeforces Contests/Round 1043 (Div 3)/C1.cpp"
        "CF Archive/1132F.cpp"
        "LIT Contest/sample.cpp"
        "LIT Contest/a.cpp"
        "LIT Contest/d.cpp"
        "CF Archive/1359D.cpp"
        "CF Archive/432D.cpp"
        "Codeforces Contests/Round 1044 (Div 2)/A.cpp"
        "Codeforces Contests/Round 1044 (Div 2)/B.cpp"
        "Codeforces Contests/Round 1044 (Div 2)/C.cpp"
        "AtCoder Beginner Contests/420/a.cpp"
        "AtCoder Beginner Contests/420/c.cpp"
        "AtCoder Beginner Contests/420/d.cpp"
        "AtCoder Beginner Contests/420/e.cpp"
        "Codeforces Contests/Round 1045 (Div 2)/a.cpp"
        "Codeforces Contests/Round 1045 (Div 2)/b.cpp"
        "Codeforces Contests/Round 1045 (Div 2)/c.cpp"
        "CF Archive/1364C.cpp"
        "CF Archive/1749C.cpp"
        "CF Archive/1766D.cpp"
        "CF Archive/1987D.cpp"
        "Codeforces Contests/Round 1046 (Div 2)/a.cpp"
        "Codeforces Contests/Round 1046 (Div 2)/b.cpp"
        "Codeforces Contests/Round 1046 (Div 2)/c.cpp"
        "Codeforces Contests/Round 1046 (Div 2)/d.cpp"
        "Codeforces Contests/Round 1046 (Div 2)/f1.cpp"
        "CF Archive/118E.cpp"
        "CF Archive/412D.cpp"
        "CF Archive/1277E.cpp"
        "CF Archive/1620E.cpp"
        "Codeforces Contests/Round 1047 (Div 3)/a.cpp"
        "Codeforces Contests/Round 1047 (Div 3)/b.cpp"
        "Codeforces Contests/Round 1047 (Div 3)/c.cpp"
        "Codeforces Contests/Round 1047 (Div 3)/g.cpp"
)
