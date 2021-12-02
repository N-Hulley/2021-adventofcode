
def parse_lines(lines):
  parsed_lines = []
  for line in lines:
    if line.isdigit(): 
      parsed_lines.append(int(line))
  return parsed_lines

def get_line_sums(lines, increment_amount:int = 3):
  parsed_lines = parse_lines(lines)
  line_sums = []
  for i in range(len(lines)):
    line_sum = 0
    for j in range(increment_amount):
      try:
        line_sum += parsed_lines[i + j]
      except:
        next
    line_sums.append(line_sum)
  return line_sums

higher_count = 0
last_line_sum = False

lines = open("input.txt", "r").read().split("\n")
for line_sum in get_line_sums(lines):
  if last_line_sum and line_sum > last_line_sum:
    higher_count += 1
  last_line_sum = line_sum

print(higher_count)