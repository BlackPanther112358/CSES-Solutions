import os
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
    if not os.path.isdir(f"../{topic}"): return
    with open(f"../{topic}/README.md", "w") as file:
        file.write(f"# {topic}\n")
        for question in QUESTIONS[topic]:
            # print(f{"".join(question.split()).cpp})
            if(os.path.isfile(f"../{topic}/{''.join(question.split())}.cpp")):
                file.write(f" - [{question}]({''.join(question.split())}.cpp)\n")
            else:
                file.write(f" - {question}\n")

def main()->None:
    """Main function"""
    load_questions()
    for topic in QUESTIONS.keys():
        update_questions(topic)

if __name__ == "__main__":
    main()
else:
    raise Exception("This file was not created to be imported")
