# Katarzna Trzos
# Lista 3
# Zadnaie 3

def find_loc(maze, lett):
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            if maze[i][j] == lett:
                return (i, j)
    return None


def find_path(maze):

    rows, cols = len(maze), len(maze[0])
    start = find_loc(maze, "S")
    end = find_loc(maze, "E")

    parent = {}
    queue = []
    queue.append(start)

    while queue:
        current = queue.pop()

        if current == end:
            break

        # gorna komorka
        row, col = current[0] - 1, current[1]
        if 0 <= row < rows and 0 <= col < cols and maze[row][col] != 'X' and (row, col) not in parent:
            parent[(row, col)] = current
            queue.append((row, col))

        # dolna komorka
        row, col = current[0] + 1, current[1]
        if 0 <= row < rows and 0 <= col < cols and maze[row][col] != 'X' and (row, col) not in parent:
            parent[(row, col)] = current
            queue.append((row, col))

        # lewa komorka
        row, col = current[0], current[1]-1
        if 0 <= row < rows and 0 <= col < cols and maze[row][col] != 'X' and (row, col) not in parent:
            parent[(row, col)] = current
            queue.append((row, col))

        # prawa komorka
        row, col = current[0], current[1] + 1
        if 0 <= row < rows and 0 <= col < cols and maze[row][col] != 'X' and (row, col) not in parent:
            parent[(row, col)] = current
            queue.append((row, col))

    # Odtwórz ścieżkę od końca do początku
    path = []
    while current != start:
        path.append(current)
        current = parent[current]

    path.append(start)
    return path[::-1]


maze1 = [
    ["S", " ", " ", "X"],
    ["X", "X", " ", " "],
    ["X", " ", " ", "X"],
    ["E", " ", "X", "X"]
]

path1 = find_path(maze1)
print(path1)

maze2 = [
    ["X", "S", " ", "X", "X", "X", "X", "X", "X", "X", "X", "X"],
    ["X", " ", " ", "X", "X", "X", " ", " ", " ", " ", "X", "X"],
    ["X", " ", " ", "X", "X", "X", " ", "X", "X", " ", "X", "X"],
    ["X", "X", " ", " ", "X", " ", " ", "X", "X", " ", "X", "X"],
    ["X", "X", " ", " ", "X", "X", "X", "X", " ", " ", "X", "X"],
    ["X", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X", "X"],
    ["X", "X", "X", "X", "X", "X", "X", "X", "X", " ", "X", "X"],
    ["X", "X", " ", " ", " ", "X", " ", " ", " ", " ", "X", "X"],
    ["X", "X", "X", "X", " ", "X", "X", " ", "X", " ", "X", "X"],
    ["X", "X", " ", "X", " ", " ", " ", " ", "X", " ", "X", "X"],
    ["X", "X", "X", "X", "X", "X", "X", "X", "X", " ", "X", "X"],
    ["X", "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X"],
    ["X", "X", " ", " ", " ", " ", " ", " ", " ", " ", "E", " "],
    ["X", "X", "X", "X", "X", "X", "X", "X", "X", "X", " ", "X"],
    ["X", "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "],
    ["X", "X", "X", "X", "X", "X", "X", "X", "X", "X", " ", "X"]
]

path2 = find_path(maze2)
print(path2)
