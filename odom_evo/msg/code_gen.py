#!/usr/bin/python3
'''
Author: Alex.Song
Date: 2021-02-20 18:54:17
LastEditors: Alex.Song
LastEditTime: 2021-02-20 19:08:14
Description: file content
FilePath: /miva-apa/src/message/code_gen.py
'''
import sys
import os
import shutil


def idl_generate_code():
    file_list = ""
    files = os.listdir("./")

    for filename in files:
        if filename.endswith('.idl'):
            file_list += "{} ".format(filename)

#    command_str = "/home/xp/git/fastdds-gen/scripts/fastddsgen -typeros2 {}".format(file_list)
    command_str = "/home/haigang/chg/code/dds0427/rclcpp/third_party/Linux/x86_64/scripts/fastddsgen -typeros2 {}".format(file_list)

    os.system(command_str)
    #print(command_str)

if __name__ == "__main__":
    os.chdir("./idl/")
    idl_generate_code()

    include_path = "../include/"
    src_path = "../src/"

    if not os.path.exists(include_path):
        os.makedirs(include_path)

    if not os.path.exists(src_path):
        os.makedirs(src_path)

    files = os.listdir("./")
    for filename in files:
        if filename.endswith('.hpp'):
            shutil.move(filename, os.path.join(include_path, filename))
        elif filename.endswith('.cpp'):
            shutil.move(filename, os.path.join(src_path, filename))
