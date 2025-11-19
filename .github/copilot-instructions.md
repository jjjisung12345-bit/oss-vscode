# Copilot instructions — repo-specific guidance

This repository is a minimal C project. The goal of this file is to help AI coding agents (Copilot/GitHub AI) be immediately productive by describing the project shape, developer workflows, and concrete examples of patterns and fixes.

- **Project shape:** single C source file `hello.c`, plus `README.md` in the repo root. `hello.c` reads numeric data from `data.txt` and compares arrays.

- **How to build:** a VS Code task exists named `C/C++: gcc build active file` that runs the compiler with:

  `gcc -fdiagnostics-color=always -g <file> -o <fileDir>/<fileBasenameNoExtension>`

  Quick manual build command (from repo root):

  `gcc -fdiagnostics-color=always -g hello.c -o hello`

- **How to run:** the program expects a `data.txt` in the same directory. Example `data.txt` layout (inferred from `hello.c`):

  - First line: integer `tot` (number of elements in the data file)
  - Next `tot` integers: the data array
  - Next: an integer `num` (number of query items) — note: the current program reads `num` from the file but reads the query values from stdin; check before changing this behaviour

  Run with: `./hello` (ensure `data.txt` exists and provide query ints on stdin if required).

- **Key files to inspect:** `hello.c` — contains the program logic and several fragile spots; `README.md` — repository metadata (minimal).

- **Common patterns & important details to preserve or check:**
  - Dynamic allocation using `malloc` and `free` for arrays.
  - File I/O with `fopen`, `fscanf`, `fclose`.
  - Use of `scanf` to read from stdin — the mix of file and stdin for inputs is intentional in the code but likely a source of bugs; confirm expected UX before changing.

- **Concrete, discoverable issues to reference in PRs / fixes:**
  - `fscanf(fp, "%d", data[i])` should pass the address: `&data[i]`.
  - `scanf("%d", arr[i])` should pass the address: `&arr[i]`.
  - Check return values from `fopen`, `fscanf`, `scanf`, and `malloc` before use.
  - Consider consistent input source: either read all inputs from `data.txt` or from stdin; document the chosen approach.

- **When creating changes / PRs:**
  - Keep changes minimal and focused (fix one bug or improve one behavior per PR).
  - Provide a brief explanation in the PR description that references the lines in `hello.c` you changed and why.
  - Run the build command shown above and demonstrate a manual run in the PR description (include sample `data.txt` and the command used).

- **What not to do without explicit approval:**
  - Large refactors (split into multiple files, introduce heavy build systems, or change project layout) — this is a tiny example project, so major restructuring should be discussed first.

If any parts of the program's intended behavior are unclear (for example whether query values should come from `data.txt` or stdin), ask the repo owner before changing the input source. Minor fixes for correctness (addressing the `&` bugs, checking return values) are safe and expected.

If you want, I can open a PR that applies the minimal correctness fixes (address-of bugs, add basic error checks, and an example `data.txt`). Would you like me to implement that now?
