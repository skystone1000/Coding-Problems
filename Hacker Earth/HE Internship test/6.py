# Q6.What is the output of the following python code

class easter:
    def __init__(self, id):
        self.id = s2(id)
        id = "100"

temp = easter(10)
print (temp.id)

"""
OUTPUT
skystone@skystone-HP-Notebook:/opt/lampp/htdocs/github/Coding-Problems/Hacker Earth/HE Intern
ship test$ p
ython3 6.py
  File "6.py", line 9
    print temp.id
          ^
SyntaxError: Missing parentheses in call to 'print'. Did you mean print(temp.id)?
skystone@skystone-HP-Notebook:/opt/lampp/htdocs/github/Coding-Problems/Hacker Earth/HE Internship test$ 
python3 6.py
Traceback (most recent call last):
  File "6.py", line 8, in <module>
    temp = easter(10)
  File "6.py", line 5, in __init__
    self.id = s2(id)
NameError: name 's2' is not defined
"""