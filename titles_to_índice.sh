#!/bin/bash
[[ !"$(translater -h)" ]] && echo 'ERROR: intall TextAnalyzer before: "pip install --user git+http://github.com/RoboCopGay/TextAnalyzer"' > /dev/stderr | exit
cat readme.md|egrep --color=auto '^#{1,3}\ .{1,}'| translater -c mdtiles_to_mdlinks.yml | translater "{'\(': '', '\)': ''}"
