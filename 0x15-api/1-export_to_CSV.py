#!/usr/bin/python3
""" api to csv"""
import csv
import requests
from sys import argv

if __name__ == "__main__":
    user = argv[1]
    url_user = "https://jsonplaceholder.typicode.com/users/" + user
    r = requests.get(url_user)
    user_name = r.json().get("username")
    task = url_user + "/todos"
    r = requests.get(task)
    tasks = r.json()

    with open("{}.csv".format(user), "w") as vfile:
        for task in tasks:
            completed = task.get("completed")

            title_t = task.get("title")
            vfile.write(f'"{user}","{user_name}","{completed}","{title_t}"\n')
