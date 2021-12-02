higher_count = 0
last_line = ''
for line in open("input.txt", "r"):
  if last_line and int(line) > int(last_line):
    higher_count += 1
  last_line = line

print(higher_count)