vcpkg_from_github(
	OUT_SOURCE_PATH SOURCE_PATH
	REPO atcoder/ac-library
	REF v1.3
	SHA512 1073ea92c56176c46e28358c7748777f175c88af94d0aec3f3811364a1d8847f87716fecdbc2e9c0e8b66f98dfd3bb573a9a80b8cec2ba7f04d8d3ceadcd6eb1
	HEAD_REF master
)

file(INSTALL "${SOURCE_PATH}/atcoder" DESTINATION "${CURRENT_PACKAGES_DIR}/include")
file(INSTALL "${SOURCE_PATH}/atcoder/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}" RENAME copyright)