#!/usr/bin/python3
"""
Returns to-do list information for a given employee ID.
"""

import requests
import sys


def fetch_employee_tasks(employee_id):
    """
    Fetches and prints the to-do list information
    """
    url = "https://jsonplaceholder.typicode.com/"
    user = requests.get(url + "users/{}".format(employee_id)).json()

    params = {"userId": employee_id}
    todos = requests.get(url + "todos", params).json()
    completed = [t.get("title") for t in todos if t.get("completed")]
    print(
        "Employee {} is done with tasks({}/{}):".format(
            user.get("name"), len(completed), len(todos)
        )
    )

    [print("\t {}".format(complete)) for complete in completed]


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 script.py <employee_id>")
        sys.exit(1)
    employee_id = sys.argv[1]
    fetch_employee_tasks(employee_id)
