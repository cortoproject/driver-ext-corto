
#include <driver.ext.corto>
#include <corto>

static
int cortoscript_load_file(
    char *file,
    int argc,
    char* argv[],
    void* ctx)
{
    ast_Node ast = cortoscript_ast_parse_file(file, false);
    if (!ast) {
        goto error;
    }

    ut_try( cortoscript_ast_declare(root_o, file, ast), NULL);

    return 0;
error:
    return -1;
}

int cortomain(int argc, char *argv[]) {
    ut_try(ut_use("corto.script.ast", 0, NULL), NULL);
    ut_try(ut_use("corto.script.declare", 0, NULL), NULL);
    ut_load_register("corto", cortoscript_load_file, NULL);
    return 0;
error:
    return -1;
}
