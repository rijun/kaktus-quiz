#!/usr/bin/env bash
for i in *.ui
do
  ui_filename=$(echo "$i" | cut -d '.' -f 1)
  ../venv/bin/pyside2-uic "$i" > ../quiz_creator/ui_classes/ui_"$ui_filename".py
done