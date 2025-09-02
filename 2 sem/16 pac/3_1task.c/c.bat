cl /c /O2 level1.c
cl /c /O2 level2.c
cl /c /O2 level3.c
lib /OUT:myblas.lib level1.obj level2.obj level3.obj
