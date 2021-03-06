/*
 * This file is part of the StegX project.
 * Copyright (C) 2018  StegX Team
 * 
 * StegX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include "cmocka.h"

#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "stegx.h"
#include "common.h"

/*
 * Teste la vérification du format BMP.
 * */

/* pixels de 16 bits */
void test_file_bmp_v1(void **state)
{
    (void)state;
    FILE *f = fopen("../../../env/test/bmp/test1.bmp", "r");
    assert_non_null(f);
    assert_int_equal(stegx_test_file_bmp(f), BMP_COMPRESSED);
    fclose(f);
}

/* pixels de 16 bits */
void test_file_bmp_v2(void **state)
{
    (void)state;
    FILE *f = fopen("../../../env/test/bmp/test2.bmp", "r");
    assert_non_null(f);
    assert_int_equal(stegx_test_file_bmp(f), BMP_COMPRESSED);
    fclose(f);
}

/* pixels de 16 bits */
void test_file_bmp_v3(void **state)
{
    (void)state;
    FILE *f = fopen("../../../env/test/bmp/test3.bmp", "r");
    assert_non_null(f);
    assert_int_equal(stegx_test_file_bmp(f), BMP_COMPRESSED);
    fclose(f);
}

 /* pixels de 24 bits */
void test_file_bmp_v4(void **state)
{
    (void)state;
    FILE *f = fopen("../../../env/test/bmp/test4.bmp", "r");
    assert_non_null(f);
    assert_int_equal(stegx_test_file_bmp(f), BMP_UNCOMPRESSED);
    fclose(f);
}

/* pixels de 32 bits */
void test_file_bmp_v5(void **state)
{
    (void)state;
    FILE *f = fopen("../../../env/test/bmp/test5.bmp", "r");
    assert_non_null(f);
    assert_int_equal(stegx_test_file_bmp(f), BMP_COMPRESSED);
    fclose(f);

}

void test_file_bmp_v6(void **state)
{
    (void)state;
    FILE *f = fopen("../../../env/test/bmp/test6.bmp", "r");
    assert_non_null(f);
    assert_int_equal(stegx_test_file_bmp(f), BMP_COMPRESSED);
    fclose(f);
}

int main(void)
{
    /* Structure CMocka contenant la liste des tests. */
    const struct CMUnitTest bmp_tests[] = {
        cmocka_unit_test(test_file_bmp_v1),
        cmocka_unit_test(test_file_bmp_v2),
        cmocka_unit_test(test_file_bmp_v3),
        cmocka_unit_test(test_file_bmp_v4),
        cmocka_unit_test(test_file_bmp_v5),
        cmocka_unit_test(test_file_bmp_v6),

    };

    /* Exécute les tests. */
    return cmocka_run_group_tests(bmp_tests, NULL, NULL);
}
