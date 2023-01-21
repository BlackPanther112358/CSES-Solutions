import os
import json
import shutil
import pytz
from datetime import datetime
import logging

LOG_FILE = "add_quesion.log"
QUESTION_FILE = "questions.json"
QUESTIONS:dict[str:list[str]]
SOLUTION_FILE = "solution.cpp"

def get_current_time()->str:
    """Returns the current time in IST"""
    return datetime.now(pytz.timezone('Asia/Kolkata')).strftime("%a %b %d %H:%M:%S %Y")

def load_questions()->None:
    """Loads the questions from the question file"""
    global QUESTIONS
    with open(QUESTION_FILE, "r") as file:
        QUESTIONS = json.load(file)

def parse_file()->str:
    """Parses the solution file and returns the question name"""
    with open(SOLUTION_FILE, "r") as file:
        data = file.read().splitlines(True)
        if not data[0].startswith("//"):
            return "PARSE_ERROR"
        else:
            question_name = data[0][2:].strip()
    with open(SOLUTION_FILE, "w") as file:
        file.writelines(data[1:])
    return question_name

def get_topic(question:str)->str:
    """Gets the topic from the user"""
    for topic in QUESTIONS:
        if question in QUESTIONS[topic]:
            return topic
    return "UNDEFINED"

def copy_file(topic:str, question:str)->None:
    """Copies the solution file to the topic folder"""
    shutil.copyfile(SOLUTION_FILE, f"../{topic}/{''.join(question.split())}.cpp")

def update_README(topic:str)->None:
    """Updates the README file for a topic"""
    if not os.path.isdir(f"../{topic}"): return
    with open(f"../{topic}/README.md", "w") as file:
        file.write(f"# {topic}\n")
        for question in QUESTIONS[topic]:
            if(os.path.isfile(f"../{topic}/{''.join(question.split())}.cpp")):
                file.write(f" - [{question}]({''.join(question.split())}.cpp)\n")
            else:
                file.write(f" - {question}\n")

def main()->None:
    """Main function"""

    logging.basicConfig(filename=LOG_FILE, level=logging.INFO)
    logger = logging.getLogger(__name__)

    logger.info(f"Starting add_question.py at {get_current_time()}")

    load_questions()
    question_name = parse_file()
    if question_name == "PARSE_ERROR":
        logger.info("Question name not found in solution.cpp")
        return
    topic = get_topic(question_name)

    if topic == "UNDEFINED":
        logger.info("Error: question not found in questions.json")
        return
    logger.info(f"Question: {question_name} Topic: {topic} found")

    if not os.path.isdir(f"../{topic}"):
        logger.info(f"Creating directory ../{topic}")
        os.mkdir(f"../{topic}")

    copy_file(topic, question_name)

    logger.info(f"Updating README.md for {topic}")
    update_README(topic)

    logger.info(f"Program finished at {get_current_time()}")

    return

if __name__ == "__main__":
    main()
else:
    raise Exception("This file was not created to be imported")
