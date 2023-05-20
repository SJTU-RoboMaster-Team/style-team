# input README.md
import re
import os


HEAD = '---\n' \
    'layout: post\n' \
    'title: C++ 代码风格指南\n' \
    'categories: [视觉, 电控, C++, 没人用, 冷门]\n' \
    'author: Julyfun\n' \
    '---\n\n'

ORI_PIC_SUF = r'(jpg|png|jpeg)'
TAR_PIC_PATH = '/assets/2023-05-20-cpp-style-guide/'


def parse(path) -> str:
    res = ''
    son_list = []

    with open(path, 'r') as raw:
        di = os.path.dirname(raw.name)
        while 1:
            line = raw.readline()
            if line == '':
                break

            file_link_pat = r"^#+ \[.+\]\(.+\.md\)$"
            mat = re.match(file_link_pat, line)
            if mat:
                file_pat = r'\((.+\.md)\)'
                fi = re.search(file_pat, line).group(1)
                son_list.append(fi)
                raw.readline()
                continue

            pic_link_pat = r'^!\[.*\]\(.+\.' + ORI_PIC_SUF + r'\)$'
            mat = re.match(pic_link_pat, line)
            if mat:
                pic_pat = r'\((.+\.' + ORI_PIC_SUF + r')\)'
                pic = re.search(pic_pat, line).group(1)
                last_slash = pic.rfind('/')
                if last_slash != -1:
                    pic = pic[last_slash + 1:]
                res += f'![]({TAR_PIC_PATH}{pic})\n'
                continue

            res += line
        for name in son_list:
            res += parse(di + '/' + name)
            if name != son_list[-1]:
                res += '\n'
    return res


with open('../build/blog.md', 'w') as f:
    res = HEAD + parse('../README.md')
    f.write(res)
