# input README.md
import re
import os

PIC_PATH = 'assets'


def parse(path) -> str:
    res = ''
    son_list = []
    file_link_pat = r"^#+ \[.+\]\(.+\.md\)$"
    file_pat = r'\((.+\.md)\)'
    pic_link_pat = r'^!\[.*\]\(.+\.(jpg|png|jpeg)\)$'
    pic_pat = r'\((.+\.(jpg|png))\)'
    with open(path, 'r') as raw:
        di = os.path.dirname(raw.name)
        while 1:
            line = raw.readline()
            if line == '':
                break

            mat = re.match(file_link_pat, line)
            if mat:
                fi = re.search(file_pat, line).group(1)
                son_list.append(fi)
                raw.readline()
                continue

            mat = re.match(pic_link_pat, line)
            if mat:
                pic = re.search(pic_pat, line).group(1)
                res += f'![]({PIC_PATH}/{pic})\n'
                continue

            res += line
        for name in son_list:
            res += parse(di + '/' + name)
            if name != son_list[-1]:
                res += '\n'
    return res


with open('../build/blog.md', 'w') as f:
    res = parse('../README.md')
    f.write(res)
