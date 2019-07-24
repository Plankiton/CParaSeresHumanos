from sys import argv

st = ''
for coisa in argv[1:]:
    st += '\n'+coisa
st = st.strip()

def org ( coisa ):
    coisa = coisa.lower()
    coisa = '-'.join(coisa.split(" "))

    simbols = "!@#$%&*()=+[]{}/?\\;:.><,|"

    out = ""
    for char in coisa:
        if char not in simbols:
            out += char
    return out

for item in st.split('\n'):
    print("[{}](#{})".format(item, org(item)))
