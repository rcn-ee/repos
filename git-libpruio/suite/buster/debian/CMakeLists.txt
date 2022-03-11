IF(${CMAKE_SYSTEM_VERSION} VERSION_LESS 4)
  SET(osvers wheezy)
ELSE()
  SET(osvers jessie)
ENDIF()

# check for Debian packaging tools
FIND_PROGRAM(deb_exe debuild)
IF(NOT deb_exe)
  MSG_LOG("!! no target <deb> (Debian tools missing - tried command debuild)")
  RETURN()
ENDIF()
MSG_LOG(">> target <deb> OK!")

ADD_CUSTOM_TARGET(Install-Debian
  ${CMAKE_COMMAND}
  -D "BUILD_TYPE=Release"
  -D "CMAKE_INSTALL_COMPONENT=Debian"
  -D "CMAKE_INSTALL_PREFIX=/usr"
  -P "${CMAKE_BINARY_DIR}/cmake_install.cmake"
  )
SET(bbbdir ${CMAKE_SOURCE_DIR}/src/examples/BBB)

# in-source: create target deb for in-source debuild
IF(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  ADD_CUSTOM_TARGET(deb
    COMMAND ${CMAKE_COMMAND} -E remove ${bbbdir}
    COMMAND cp    compat.${osvers} compat
    COMMAND cp   control.${osvers} control
    COMMAND cat   control.packages >> control
    COMMAND cp changelog.${osvers} changelog
    COMMAND echo "doxy/html" > ${PROJ_NAME}-doc.docs
    COMMAND cd ${CMAKE_SOURCE_DIR} && ${deb_exe} ${DEBUILD_FLAGS}
    )
  FOREACH(tar ${FB_EXAMPLES})
    INSTALL(PROGRAMS ../src/examples/${tar} DESTINATION bin RENAME pruio_${tar})
  ENDFOREACH(tar)
  RETURN()
ENDIF()

# out-of-source: create clean build subfolder
SET(src # files & dirs to copy from root dir
  CMakeLists.txt
  *.md
  cmake
  debian
  doxy
  src
  )
# create target deb for out-of-source debuild
SET(bdir ${CMAKE_CURRENT_BINARY_DIR}/${PROJ_NAME})
SET(debdir ${bdir}/debian)
ADD_CUSTOM_TARGET(deb rm -rf ${bdir}
  COMMAND ${CMAKE_COMMAND} -E remove ${bbbdir}
  COMMAND mkdir -p ${bdir}
  COMMAND cd ${CMAKE_SOURCE_DIR} && cp -r ${src} ${bdir}
  COMMAND ${CMAKE_COMMAND} -E remove ${bdir}/src/python/libpruio/*.pyc
  COMMAND cp    ${CMAKE_CURRENT_SOURCE_DIR}/compat.${osvers} ${debdir}/compat
  COMMAND cp   ${CMAKE_CURRENT_SOURCE_DIR}/control.${osvers} ${debdir}/control
  COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/control.packages >> ${debdir}/control
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/changelog.${osvers} ${debdir}/changelog
  COMMAND echo "../../doxy/html" > ${debdir}/${PROJ_NAME}-doc.docs
  COMMAND cd ${bdir} && ${deb_exe} ${DEBUILD_FLAGS}
  )

# Package building
#
# 1) update build tree on PC, make doc_htm, make doc_www
# 2) update build tree on 3.8, copy html(PC) -> build/doxy, make deb, dput
# 3) update build tree on 4.4, copy html(PC) -> build/doxy, make deb, dput
