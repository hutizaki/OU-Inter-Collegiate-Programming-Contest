#!/usr/bin/env python3
"""
Start New Problem CLI: interactive prompts to create a new problem folder
and copy the appropriate template (C++ or Python) into it.
"""

import os
import shutil
import sys

try:
    import questionary
except ImportError:
    print("Missing dependency: questionary. From repo root run:")
    print("  pip install -r cli-tool/REQUIREMENTS.txt   (or pip3 on Mac/Linux)")
    sys.exit(1)

_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.dirname(_SCRIPT_DIR)

PLATFORM_CHOICES = ["ICPC Archives", "Kattis", "Code Forces"]
PLATFORM_TO_FOLDER = {
    "ICPC Archives": "ICPC Archives",
    "Kattis": "Kattis Problems",
    "Code Forces": "Code Forces Problems",
}
DIFFICULTY_CHOICES = ["Easy", "Medium", "Hard", "Not Sure"]
LANGUAGE_CHOICES = ["C++", "Python"]

CPP_TEMPLATE = "C_PLUS_PLUS_TEMPLATE.cpp"
PYTHON_TEMPLATE = "PYTHON_TEMPLATE.py"


def derive_source_filename(problem_name: str, language: str) -> str:
    """Remove spaces and keep title-case segments, e.g. '3D Printed Statues' -> '3DPrintedStatues'."""
    # Remove spaces and join (title-case segments preserved)
    base = "".join(word for word in problem_name.split())
    if not base:
        base = "problem"
    if language == "C++":
        return f"{base}.cpp"
    return f"{base}.py"


def main():
    print("\n  Start New Problem\n")

    platform = questionary.select(
        "Which platform are you practicing on?",
        choices=PLATFORM_CHOICES,
        use_shortcuts=True,
    ).ask()
    if platform is None:
        print("Cancelled.")
        return

    problem_name = questionary.text(
        "What is the name/code of the problem?",
        default="",
    ).ask()
    if problem_name is None:
        print("Cancelled.")
        return
    problem_name = problem_name.strip()
    if not problem_name:
        print("Error: problem name cannot be empty.")
        return

    difficulty = questionary.select(
        "What difficulty is the problem?",
        choices=DIFFICULTY_CHOICES,
        use_shortcuts=True,
    ).ask()
    if difficulty is None:
        print("Cancelled.")
        return

    language = questionary.select(
        "What language are you coding in?",
        choices=LANGUAGE_CHOICES,
        use_shortcuts=True,
    ).ask()
    if language is None:
        print("Cancelled.")
        return

    platform_folder = PLATFORM_TO_FOLDER[platform]
    target_dir = os.path.join(REPO_ROOT, platform_folder, difficulty, problem_name)
    source_filename = derive_source_filename(problem_name, language)
    target_path = os.path.join(target_dir, source_filename)

    if os.path.isdir(target_dir):
        add_anyway = questionary.confirm(
            "Folder already exists. Add file anyway? (overwrites if file exists)",
            default=False,
        ).ask()
        if add_anyway is None or not add_anyway:
            print("Skipped.")
            return
    else:
        os.makedirs(target_dir, exist_ok=True)

    template_name = CPP_TEMPLATE if language == "C++" else PYTHON_TEMPLATE
    template_path = os.path.join(REPO_ROOT, "templates", template_name)
    if not os.path.isfile(template_path):
        print(f"Error: template not found: {template_path}")
        return

    shutil.copy2(template_path, target_path)
    for name in ("input1.txt", "output1.txt"):
        p = os.path.join(target_dir, name)
        if not os.path.isfile(p):
            open(p, "w").close()
    print(f"\n  Created: {target_path}")
    print(f"  Created: input1.txt, output1.txt (paste sample input/output here)")
    print(f"  Open the file above to start coding.\n")


if __name__ == "__main__":
    main()
