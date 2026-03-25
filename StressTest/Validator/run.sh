#!/usr/bin/env bash
# Usage: ./validate.sh sol.cpp val.cpp gen.cpp numTests
g++ -O2 -std=c++17 "$1" -o .sol && g++ -O2 -std=c++17 "$2" -o .val && g++ -O2 -std=c++17 "$3" -o .gen || exit 1
trap "rm -f .sol .val .gen input out data" EXIT
for ((i=1; i<=$4; i++)); do
    ./.gen > input
    ./.sol < input > out
    cat input out > data
    res=$(./.val < data)
    if [[ "$res" != OK* ]]; then
        echo -e "Failed test $i\nInput:\n$(cat input)\nOutput:\n$(cat out)\nChecker:\n$res"
        exit 1
    fi
    echo -ne "Passed test $i"; echo ""
done
echo "Passed $4 tests"
