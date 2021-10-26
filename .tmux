#!/bin/bash
tmux new -d -s cforhumans 'nvim readme.md'
tmux split-window -h 'nvim'
tmux split-window -v 
tmux a -t cforhumans