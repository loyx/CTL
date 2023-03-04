import os
import subprocess

from rich import inspect
from rich.panel import Panel
from rich.console import Console
from rich.rule import Rule
from rich.style import Style
from rich.box import ROUNDED
from rich.markup import escape
from rich.text import Text

console = Console()

cmake_file = os.path.join('..', 'compiler')
cmake_output = os.path.join('.', 'cmake-build-debug')
target = "ctlc"

# build
cmd_seq = [
    "set HTTP_PROXY=http://localhost:1080",
    f"set HTTPS_PROXY=https://localhost:1080",
    f"cmake -G Ninja -S {cmake_file} -B {cmake_output}",
    f"cmake --build {cmake_output} --target {target} -j 16",
]

console.rule("[bold red] build section", characters="=")
for cmd in cmd_seq:
    console.print(Panel(cmd, highlight=True, border_style='blue', title="cmd", safe_box=False))
    os.system(cmd)
    console.rule("cmd: " + cmd, style='blue')
    print('\n')


# test case
include_paths = [
    os.path.join('.', 'examples')
]

console.rule("[bold red] test section", characters="=")


def testFileGen(start):
    for root, dirs, files in os.walk(start):
        for file_name in files:
            file_name: str
            if file_name.endswith(".ctl"):
                yield os.path.join(start, file_name)
        for dir_name in dirs:
            yield from testFileGen(dir_name)


test_cmd: str = f"{os.path.join(cmake_output, 'ctlc')} {{}}"
for example_path in include_paths:
    test_files = list(testFileGen(example_path))
    console.print(Panel("\n".join(test_files), title="test dir: " + example_path, safe_box=False, border_style='green'))
    for file in test_files:
        result = subprocess.run([os.path.join(cmake_output, 'ctlc'), file], stdout=subprocess.PIPE, text=True)
        console.print(Panel(escape(result.stdout), highlight=True, title=file, safe_box=False, border_style='blue'))
