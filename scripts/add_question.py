import json

QUESTION_FILE = "questions.json"
QUESTIONS:dict[str:list[str]]

def load_questions()->None:
    """Loads the questions from the question file"""
    global QUESTIONS
    with open(QUESTION_FILE, "r") as file:
        QUESTIONS = json.load(file)

def update_questions(topic:str)->None:
    """Updates the README file for a topic"""

def main()->None:
    """Main function"""
    load_questions()
    for topic in QUESTIONS.keys():
        update_questions(topic)

if __name__ == "__main__":
    main()
else:
    raise Exception("This file was not created to be imported")
