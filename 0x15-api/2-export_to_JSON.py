#!/usr/bin/python3
""" Python to get data from an API and convert to Json"""
import csv
import json
import requests
import sys


if __name__ == "__main__":
    USER_ID = sys.argv[1]
    url_to_user = "https://jsonplaceholder.typicode.com/users/" + USER_ID
    res = requests.get(url_to_user)
    """Documentation"""
    USERNAME = res.json().get("username")
    """Documentation"""
    url_to_task = url_to_user + "/todos"
    res = requests.get(url_to_task)
    tasks = res.json()

    ct_data = {USER_ID: []}
    for task in tasks:
        STATUS = task.get("completed")
        TITLE = task.get("title")
        ct_data[USER_ID].append(
            {"task": TITLE, "completed": STATUS, "username": USERNAME}
        )
    with open("{}.json".format(USER_ID), "w") as jf:
        json.dump(ct_data, jf)
