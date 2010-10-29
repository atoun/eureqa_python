CC		=	g++ -g -fPIC

BOOST_INC	=	~/Portable/boost/include
BOOST_LIB	=	~/Portable/boost/lib

PYTHON_INC	=	~/Portable/python/include/python2.7

EUREQA_INC	=	~/Portable/eureqa

TARGET		=	eureqa_python.so
CFLAGS		=	-I ${BOOST_INC} -I ${PYTHON_INC} -I ${EUREQA_INC}
LFLAGS		=	-Wl,-rpath ${BOOST_LIB} -L ${BOOST_LIB} -lboost_system -lboost_serialization -lboost_date_time -lboost_thread -lboost_python -shared 


copy : ${TARGET}
		$(shell cp -u ${TARGET} python/src)

${TARGET} : ${TARGET:.so=.cpp}
	${CC} $< ${CFLAGS} ${LFLAGS} -o $@


.PHONY : clean all

clean :	
	rm -f *.so
	
all : copy
