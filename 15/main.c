#include <stdio.h>
#include <stdlib.h>
#include <map>

typedef std::map<int, long> CacheMap;

int gridSize = 0;
CacheMap cache;

int hash(int x, int y)
{
	return (1000 * x) + y;
}

long progress(int x, int y)
{
    // if this route has been solved before then lookup that answer in the cache
    CacheMap::iterator itr = cache.find(hash(x, y));
    if (itr != cache.end())
        return (*itr).second;

    long i = 0;

    // solve it recursively
    if (x < gridSize)
        i += progress(x + 1, y);
    if (y < gridSize)
        i += progress(x, y + 1);

    if (x == gridSize && y == gridSize)
        return 1;

    // store this answer in the cache so that we don't have to do it again
    cache.insert(CacheMap::value_type(hash(x, y), i));

    return i;
}

int main(int argc, char *argv[])
{
	argc--;
	argv++;
	gridSize = argc > 0 ? atoi(argv[0]) : 20;

	long total = progress(0, 0);
	printf("%ld\n", total);

	return 0;
}
