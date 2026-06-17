#!/usr/bin/env python3


def secure_archive(filename: str,
                   mode: str = 'r',
                   content: str = '') -> tuple[bool, str]:
    if mode == 'r':
        try:
            with open(filename, mode) as f:
                inhalt: str = f.read()
        except OSError as e:
            return (False, str(e))  
        else:
            return (True, inhalt)  
    if mode == 'w':
        try:
            with open(filename, mode) as f:
                f.write(content)
            return (True, "Content successfully written to file")
        except OSError as e:
            return (False, str(e))


if __name__ == "__main__":
    print("=== Cyber Archives Security ===\n")
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive('/not/existing/file'))
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    print(secure_archive('/etc/master.passwd'))
    print("\nUsing 'secure_archive' to read from a regular file:")
    print(secure_archive('ancient_fragment.txt'))
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    _, content = secure_archive('ancient_fragment.txt')
    print(secure_archive('new_fragment.txt', 'w', content))
