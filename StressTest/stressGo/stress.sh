#!/bin/bash

set -e  # Immediately ragequit on failure because I have standards 😤

CXX_FLAGS="-std=c++17 -O3 -march=native -DNDEBUG"
MAX_TESTS=1000

echo "🔧 Compiling your spaghetti 🍝"

# Compile C++ files
for src in Gen.cpp Brute.cpp; do
    exe="${src%.cpp}"
    g++ $src -o $exe $CXX_FLAGS && echo "✅ Compiled $src → $exe"
done

# Compile Go solution
go build -o Sol Sol.go && echo "✅ Compiled Sol.go → Sol"

echo "🔥 Starting emotional trauma testing loop..."

# Tsundere insult pool for emotional validation
declare -a ROASTS=(
    "Is that the best you can do?"
    "Try harder, dummy."
    "You barely passed. Don’t get cocky."
    "Lucky. I bet Brute carried you."
    "Tch. Acceptable… I guess."
    "Honestly shocked that passed. Like. Genuinely."
    "Your code is mid but whatever."
    "If Bessie saw this, she’d moo in disappointment."
    "Goroutines won't save you from a WA."
)

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
RESET='\033[0m'

for ((i=1; i<=MAX_TESTS; i++)); do
    echo -e "${CYAN}[$i/${MAX_TESTS}] Generating chaos...${RESET}"

    ./Gen > input.txt
    ./Sol < input.txt > output.txt
    ./Brute < input.txt > expected.txt

    if ! diff -q output.txt expected.txt > /dev/null; then
        echo -e "${RED}💔 FAILURE at test #$i${RESET}"
        echo -e "${YELLOW}--- INPUT ---${RESET}"
        cat input.txt
        echo -e "${YELLOW}--- YOUR OUTPUT ---${RESET}"
        cat output.txt
        echo -e "${YELLOW}--- EXPECTED OUTPUT ---${RESET}"
        cat expected.txt
        echo -e "${RED}😭 YOU HAVE BEEN PUBLICLY SHAMED.${RESET}"
        exit 1337
    else
        roast=${ROASTS[$RANDOM % ${#ROASTS[@]}]}
        echo -e "${GREEN}✅ Test #$i passed. $roast${RESET}"
    fi
done

echo -e "${GREEN}🎉 All $MAX_TESTS tests passed!${RESET} B-baka… don’t expect praise every time…"
