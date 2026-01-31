#!/usr/bin/env bash
cd "$(dirname "$0")"

# Check Python 3
if ! command -v python3 &>/dev/null; then
    echo "Python 3 is required. Install from python.org or: brew install python3"
    exit 1
fi

# Use project venv to avoid "externally-managed-environment" on macOS/Homebrew (PEP 668)
VENV_PYTHON="cli-tool/.venv/bin/python"
if [[ -x "$VENV_PYTHON" ]]; then
    PYTHON="$VENV_PYTHON"
else
    PYTHON="python3"
fi

# Check questionary (in venv or system)
if ! "$PYTHON" -c "import questionary" 2>/dev/null; then
    if [[ -x "$VENV_PYTHON" ]]; then
        echo "Missing dependency: questionary (in venv)"
        printf "Install dependencies into project venv? (y/n) "
    else
        echo "Missing dependency: questionary"
        echo "macOS/Homebrew Python is externally managed. We'll use a project virtual environment."
        printf "Create venv and install dependencies? (y/n) "
    fi
    read -r -n 1 REPLY
    echo
    case "$REPLY" in
        y|Y)
            if [[ ! -x "$VENV_PYTHON" ]]; then
                echo "Creating cli-tool/.venv ..."
                if ! python3 -m venv cli-tool/.venv; then
                    echo "Failed to create venv."
                    exit 1
                fi
                PYTHON="$VENV_PYTHON"
            fi
            if ! "$PYTHON" -m pip install -r cli-tool/REQUIREMENTS.txt; then
                echo "Install failed. From repo root run: $PYTHON -m pip install -r cli-tool/REQUIREMENTS.txt"
                exit 1
            fi
            ;;
        *)
            echo "From repo root: python3 -m venv cli-tool/.venv && cli-tool/.venv/bin/pip install -r cli-tool/REQUIREMENTS.txt"
            exit 0
            ;;
    esac
fi

"$PYTHON" cli-tool/START_NEW_PROBLEM.py
