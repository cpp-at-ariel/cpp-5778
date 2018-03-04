/**
 * @author Ofir Pele
 * @since 2017
 */

#include "IntBuffer.hpp"

void IntBuffer::copyVals(const IntBuffer& other) {
	for (size_t i= 0; i<other.size(); ++i) {
		(*this)[i]= other[i];
	}
}

void IntBuffer::freeMemory() {
#ifdef INT_BUFFER_MALLOC_REALLOC_VERSION
		free(_buf);
#else
		delete[] _buf;
#endif
}
	
int* IntBuffer::getMemory(size_t size) {
#ifdef INT_BUFFER_MALLOC_REALLOC_VERSION
	return (int*)malloc(size*sizeof(int));
#else
	return new int[size];
#endif
}
