#!/usr/bin/python3
"""
A script to export data in the JSON format
"""
import json
import requests

if __name__ == "__main__":
    users_url = "https://jsonplaceholder.typicode.com/users"
    user_data = requests.get(users_url, verify=False).json()
    user_tasks = {}
    usernames = {}

    for user in user_data:
        user_id = user.get("id")
        user_tasks[user_id] = []
        usernames[user_id] = user.get("username")

    todos_url = "https://jsonplaceholder.typicode.com/todos"
    todo_data = requests.get(todos_url, verify=False).json()

    [
        user_tasks.get(task.get("userId")).append(
            {
                "task": task.get("title"),
                "completed": task.get("completed"),
                "username": usernames.get(task.get("userId")),
            }
        )
        for task in todo_data
    ]

    with open("todo_all_employees.json", "w") as json_file:
        json.dump(user_tasks, json_file)
