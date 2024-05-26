import re
import sys

def parse_spec_line(line):
    match = re.match(r'@\s+\w+\s+(\w+)\(.*?\)', line)
    if match:
        func_name = match.group(1)
        return func_name
    return None

def convert_spec_to_def(spec_file, def_file, library_name):
    with open(spec_file, 'r') as spec, open(def_file, 'w') as def_f:
        def_f.write(f'LIBRARY {library_name}\nEXPORTS\n')
        for line in spec:
            func_name = parse_spec_line(line)
            if func_name:
                def_f.write(f'    {func_name}\n')

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print("Usage: python spec2def.py <input.spec> <output.def> <LibraryName>")
        sys.exit(1)

    spec_file = sys.argv[1]
    def_file = sys.argv[2]
    library_name = sys.argv[3]
    convert_spec_to_def(spec_file, def_file, library_name)
    print(f"Conversion complete. Output written to {def_file}")
