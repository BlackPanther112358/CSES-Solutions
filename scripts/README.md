# Scripts

This directory contains all the supporting programs for this repository.

```requirements.txt``` contains the list of all the python packages required to run the programs. These packages can be installed using the following command (as is done while setting up the GitHub Actions):

```bash
pip install -r requirements.txt
```

The latest solution is pushed to the repository in ```solution.cpp``` file. A comment in the beginning of the file contains the problem name. 

```add_solution.py``` is the main program which is run using GitHub Actions whenever a new solution is pushed to the repository. It can also be run locally using the following command:

```bash
python3 add_solution.py
```

The program reads the problem name from the comment in the beginning of the solution file, and adds the solution to the appropriate folder. It also updates the ```README.md``` files in the repository.

In case the folder for the problem does not exist, the program creates the folder and adds the solution to it. It also creates the ```README.md``` file for the folder, and adds the problem name and link to the solution in it. The program also updates the ```README.md``` file in the main folder, and adds the link to the folder in the ```Topics``` section.