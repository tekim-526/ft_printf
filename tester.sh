#!/bin/bash

# 이거를 프로젝트 폴더로 수정하세요!
PROJ_PATH=.

# ### 안내:
# https://github.com/PandaCoustik/Test-42
# 에 나와있는 ft_printf 테스트들에 대하여 자동으로 실행시켜주는 스크립트입니다.
# 각 테스트에 대한 유의사항은 아래에 기재되어 있습니다.
# 자유롭게 주석처리하여 원하는 것만 실행해도 됩니다.
# (안내) 2020.11.2 기준으로 작동되지만, 추후 정상적으로 작동하지 않을 수 있습니다.
# (주의!) 작동 환경에 따라 예상치 못한 동작이 발생할 수 있습니다.. 반드시 git push 해두시기 바랍니다.
# (주의!) 본 스크립트는 외부 라이브러리(예:libft.a)를 사용하는 프로젝트에 대해 테스트를 거치지 않았습니다.
# (주의!) 본 스크립트는 프로젝트 폴더 내에 테스트 폴더를 생성합니다. 테스트 완료후 테스트 폴더/파일이 삭제되지 않습니다.

# ### 대략적인 스크립트의 원리 ### ---------------------
# 1. 테스트를 git clone 합니다.
# 2. 테스트 폴더로 들어가 테스트를 수행하고 밖으로 빠져나옵니다.
# 3. 결과가 있을 경우, test_result.txt 에 저장합니다.

# ----------------------------------------
# ###### gitignore 하면 편한 것들 ######
# pft/
# 42TESTERS-PRINTF/
# pft_2019/
# tests451/
# printf_lover_v2/
# printf-tester/
# Test-42/
# ft_printf_test/
# **/*.o
# **/*.a
# test_result.txt
# test_all.sh
# ----------------------------------------


# 실제 프로젝트 폴더 위치로 이동
REAL_PATH=$(cd $(dirname $0) && cd ${PROJ_PATH} && pwd)
echo 프로젝트 위치: $REAL_PATH


# 테스트 적용 위해 다시 컴파일 (make re 사용)
cd $REAL_PATH
make re
echo "" > test_result.txt


# ########## 42TESTERS-PRINTF ##########
echo -e '######### 42TESTERS-PRINTF ##########' >> test_result.txt
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF
bash runtest.sh
echo "#####42TESTS-PRINTF#####" >> ../test_result.txt
cat diff.txt >> ../test_result.txt
cd ..

# ########## PFT ##########
echo -e '#########PFT##########' >> test_result.txt
git clone https://github.com/gavinfielder/pft.git pft
make re
cd pft
make re
./test
cat -e results.txt >> ../test_result.txt
cd ..

# ########## PFT_2019 ##########
echo -e '#########PFT_2019##########' >> test_result.txt
git clone https://github.com/gavinfielder/pft.git pft_2019
cd pft_2019
rm unit_tests.c
rm options-config.ini
git clone https://github.com/cclaude42/PFT_2019.git temp
cp temp/unit_tests.c .
cp temp/options-config.ini .
rm -rf temp
make re
./test
cat -e results.txt >> ../test_result.txt
cd ..


# ######### printf_lover_v2 #########
# (수동으로 동작 필요)
echo -e '######### printf_lover_v2 ##########' >> test_result.txt
git clone https://github.com/charMstr/printf_lover_v2.git
cd printf_lover_v2
./printf_lover.sh re
cd ..

# ######### printf-tester #########
echo -e '######### printf-tester ##########' >> test_result.txt
git clone https://github.com/AntoineBourin/printf-tester.git
cd printf-tester
cp ../libftprintf.a libftprintf.a
chmod +x test.sh
bash ./test.sh
echo -en "\033[0m"
cd ..


# ######### Test-42 #########
echo -e '######### Test-42 ##########' >> test_result.txt
git clone https://github.com/PandaCoustik/Test-42.git
cd Test-42/test_printf_classic
cp ../../libftprintf.a libftprintf.a
make
cd ../../