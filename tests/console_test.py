import subprocess
import sys

def run(text):
    return subprocess.run([sys.argv[1]],input=text.encode(),capture_output=True,timeout=3,check=True).stdout.decode()

assert run('')
assert run('invalid\n4\n')
assert run('1\n')
output=run('1\n3\nRegular\n0\nUrgent\n2\nUrgentLater\n2\n2\n2\n2\n4\n')
served=[line for line in output.splitlines() if 'Now serving:' in line]
assert len(served)==3
assert 'Urgent [Ticket 2]' in served[0]
assert 'UrgentLater [Ticket 3]' in served[1]
assert 'Regular [Ticket 1]' in served[2]
print('PASS: priority, FIFO ties, invalid input and EOF')
