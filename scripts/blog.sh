#!/bin/bash
set -e

python3.9 to_blog.py
scp ../build/blog.md ~/Documents/GitHub/SJTU-RoboMaster-Team.github.io/_posts/2023-05-20-cpp-style-guide.md

