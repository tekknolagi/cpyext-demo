import setuptools
from distutils.core import Extension

setuptools.setup(
    ext_modules=[
        Extension(
            "myext", sources=["myext.c"],
            extra_compile_args=['-O0', '-ggdb', '-Wall', '-Wextra'],
            language='c',
            )
        ],
)

