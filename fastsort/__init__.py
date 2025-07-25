try:
    from .fastsort import FastInsertionSort
except ImportError:
    import os
    import sys
    # Try to load from the build directory
    build_dirs = [d for d in os.listdir('build') if d.startswith('lib.')]
    if build_dirs:
        build_path = os.path.join('build', build_dirs[0])
        if build_path not in sys.path:
            sys.path.insert(0, os.path.abspath(build_path))
        from fastsort.fastsort import FastInsertionSort
    else:
        raise ImportError("Could not find compiled module. Please ensure the package is properly installed.")

__all__ = ['FastInsertionSort']
