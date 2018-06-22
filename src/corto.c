
#include <driver/ext/corto/corto.h>
#include <corto/script/ast/ast.h>
#include <corto/script/declare/declare.h>

#include <corto/corto.h>

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

    corto_try( cortoscript_ast_declare(root_o, file, ast), NULL);

    return 0;
error:
    return -1;
}

int cortomain(int argc, char *argv[]) {
    corto_try(corto_use("corto/script/ast", 0, NULL), NULL);
    corto_try(corto_use("corto/script/declare", 0, NULL), NULL);
    corto_load_register("corto", cortoscript_load_file, NULL);
    return 0;
error:
    return -1;
}
