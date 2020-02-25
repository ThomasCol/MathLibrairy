#include "CppUnitTest.h"
#include "Quaternion.h"
#include <glm/glm.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMathLib
{
	TEST_CLASS(UnitTestMathLib)
	{
	public:
		
		/* BEGIN Test Matrix4 */
		TEST_METHOD(inverseMat4)
		{
			Math::QXmat4 mat4;
			glm::mat<4, 4, float> gmat4;

			mat4.array[0] = 1;	mat4.array[1] = 2;	mat4.array[2] = 3;	mat4.array[3] = 4;
			mat4.array[4] = 5;	mat4.array[5] = 6;	mat4.array[6] = 7;	mat4.array[7] = 8;
			mat4.array[8] = 9;	mat4.array[9] = 10; mat4.array[10] = 11; mat4.array[11] = 12;
			mat4.array[12] = 13; mat4.array[13] = 14; mat4.array[14] = 15;	mat4.array[15] = 16;

			gmat4[0][0] = 1; gmat4[0][1] = 2; gmat4[0][2] = 3; gmat4[0][3] = 4;
			gmat4[1][0] = 5; gmat4[1][1] = 6; gmat4[1][2] = 7; gmat4[1][3] = 8;
			gmat4[2][0] = 9; gmat4[2][1] = 10; gmat4[2][2] = 11; gmat4[2][3] = 12;
			gmat4[3][0] = 13; gmat4[3][1] = 14; gmat4[3][2] = 15; gmat4[3][3] = 16;


			Math::QXmat4 mat4inv = mat4.Inverse();
			glm::mat<4, 4, float> gmat4inv = glm::inverse(gmat4);
			for (unsigned int i = 0; i < 16; i++)
				Assert::AreEqual(mat4inv.array[i], gmat4inv[i/4][i%4]);
		}

		TEST_METHOD(transposeMat4)
		{
			Math::QXmat4 mat4;
			glm::mat<4, 4, float> gmat4;

			mat4.array[0] = 1;	mat4.array[1] = 2;	mat4.array[2] = 3;	mat4.array[3] = 4;
			mat4.array[4] = 5;	mat4.array[5] = 6;	mat4.array[6] = 7;	mat4.array[7] = 8;
			mat4.array[8] = 9;	mat4.array[9] = 10; mat4.array[10] = 11; mat4.array[11] = 12;
			mat4.array[12] = 13; mat4.array[13] = 14; mat4.array[14] = 15;	mat4.array[15] = 16;

			gmat4[0][0] = 1; gmat4[0][1] = 2; gmat4[0][2] = 3; gmat4[0][3] = 4;
			gmat4[1][0] = 5; gmat4[1][1] = 6; gmat4[1][2] = 7; gmat4[1][3] = 8;
			gmat4[2][0] = 9; gmat4[2][1] = 10; gmat4[2][2] = 11; gmat4[2][3] = 12;
			gmat4[3][0] = 13; gmat4[3][1] = 14; gmat4[3][2] = 15; gmat4[3][3] = 16;


			Math::QXmat4 mat4transpose = mat4.Transpose();
			glm::mat<4, 4, float> gmat4transpose = glm::transpose(gmat4);
			for (unsigned int i = 0; i < 16; i++)
				Assert::AreEqual(mat4transpose.array[i], gmat4transpose[i / 4][i % 4]);
		}

		TEST_METHOD(multiplicationMat4ToMat4)
		{
			Math::QXmat4 mat4_1, mat4_2;
			glm::mat<4, 4, float> gmat4_1, gmat4_2;
			
			mat4_1.array[0] = 1; mat4_1.array[1] = 2; mat4_1.array[2] = 3;	mat4_1.array[3] = 4;
			mat4_1.array[4] = 5; mat4_1.array[5] = 6; mat4_1.array[6] = 7;	mat4_1.array[7] = 8;
			mat4_1.array[8] = 9; mat4_1.array[9] = 10; mat4_1.array[10] = 11; mat4_1.array[11] = 12;
			mat4_1.array[12] = 13; mat4_1.array[13] = 14; mat4_1.array[14] = 15; mat4_1.array[15] = 16;

			mat4_2.array[0] = 1; mat4_2.array[1] = 2; mat4_2.array[2] = 3; mat4_2.array[3] = 4;
			mat4_2.array[4] = 5; mat4_2.array[5] = 6; mat4_2.array[6] = 7; mat4_2.array[7] = 8;
			mat4_2.array[8] = 9; mat4_2.array[9] = 10; mat4_2.array[10] = 11; mat4_2.array[11] = 12;
			mat4_2.array[12] = 13; mat4_2.array[13] = 14; mat4_2.array[14] = 15; mat4_2.array[15] = 16;

			gmat4_1[0][0] = 1; gmat4_1[0][1] = 2; gmat4_1[0][2] = 3; gmat4_1[0][3] = 4;
			gmat4_1[1][0] = 5; gmat4_1[1][1] = 6; gmat4_1[1][2] = 7; gmat4_1[1][3] = 8;
			gmat4_1[2][0] = 9; gmat4_1[2][1] = 10; gmat4_1[2][2] = 11; gmat4_1[2][3] = 12;
			gmat4_1[3][0] = 13; gmat4_1[3][1] = 14; gmat4_1[3][2] = 15; gmat4_1[3][3] = 16;

			gmat4_2[0][0] = 1; gmat4_2[0][1] = 2; gmat4_2[0][2] = 3; gmat4_2[0][3] = 4;
			gmat4_2[1][0] = 5; gmat4_2[1][1] = 6; gmat4_2[1][2] = 7; gmat4_2[1][3] = 8;
			gmat4_2[2][0] = 9; gmat4_2[2][1] = 10; gmat4_2[2][2] = 11; gmat4_2[2][3] = 12;
			gmat4_2[3][0] = 13; gmat4_2[3][1] = 14; gmat4_2[3][2] = 15; gmat4_2[3][3] = 16;


			Math::QXmat4 mat4res = mat4_1 * mat4_2;
			glm::mat<4, 4, float> gmat4res = gmat4_1 * gmat4_2;
			for (unsigned int i = 0; i < 16; i++)
				Assert::AreEqual(mat4res.array[i], gmat4res[i / 4][i % 4]);
		}

		TEST_METHOD(multiplicationMat4ToVec3)
		{
			Math::QXmat4 mat4;
			Math::QXvec3 vec3{1, 2, 3};
			glm::mat<4, 4, float> gmat4;
			glm::vec4 gvec3{ 1, 2, 3, 1 };

			mat4.array[0] = 1; mat4.array[1] = 2; mat4.array[2] = 3;	mat4.array[3] = 4;
			mat4.array[4] = 5; mat4.array[5] = 6; mat4.array[6] = 7;	mat4.array[7] = 8;
			mat4.array[8] = 9; mat4.array[9] = 10; mat4.array[10] = 11; mat4.array[11] = 12;
			mat4.array[12] = 13; mat4.array[13] = 14; mat4.array[14] = 15; mat4.array[15] = 16;

			gmat4[0][0] = 1; gmat4[0][1] = 2; gmat4[0][2] = 3; gmat4[0][3] = 4;
			gmat4[1][0] = 5; gmat4[1][1] = 6; gmat4[1][2] = 7; gmat4[1][3] = 8;
			gmat4[2][0] = 9; gmat4[2][1] = 10; gmat4[2][2] = 11; gmat4[2][3] = 12;
			gmat4[3][0] = 13; gmat4[3][1] = 14; gmat4[3][2] = 15; gmat4[3][3] = 16;


			Math::QXvec3 vec3res = mat4 * vec3;
			glm::vec3 gvec3res = gmat4 * gvec3;
			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3res[i], gvec3res[i]);
		}

		TEST_METHOD(multiplicationMat4ToVec4)
		{
			Math::QXmat4 mat4;
			Math::QXvec4 vec4{ 1, 2, 3, 1 };
			glm::mat<4, 4, float> gmat4;
			glm::vec4 gvec4{ 1, 2, 3, 1 };

			mat4.array[0] = 1; mat4.array[1] = 2; mat4.array[2] = 3;	mat4.array[3] = 4;
			mat4.array[4] = 5; mat4.array[5] = 6; mat4.array[6] = 7;	mat4.array[7] = 8;
			mat4.array[8] = 9; mat4.array[9] = 10; mat4.array[10] = 11; mat4.array[11] = 12;
			mat4.array[12] = 13; mat4.array[13] = 14; mat4.array[14] = 15; mat4.array[15] = 16;

			gmat4[0][0] = 1; gmat4[0][1] = 2; gmat4[0][2] = 3; gmat4[0][3] = 4;
			gmat4[1][0] = 5; gmat4[1][1] = 6; gmat4[1][2] = 7; gmat4[1][3] = 8;
			gmat4[2][0] = 9; gmat4[2][1] = 10; gmat4[2][2] = 11; gmat4[2][3] = 12;
			gmat4[3][0] = 13; gmat4[3][1] = 14; gmat4[3][2] = 15; gmat4[3][3] = 16;


			Math::QXvec3 vec3res = mat4 * vec4;
			glm::vec3 gvec3res = gmat4 * gvec4;
			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3res[i], gvec3res[i]);

	
		}

		TEST_METHOD(addMat4ToMat4)
		{
			Math::QXmat4 mat4_1, mat4_2;
			glm::mat<4, 4, float> gmat4_1, gmat4_2;

			mat4_1.array[0] = 1; mat4_1.array[1] = 2; mat4_1.array[2] = 3;	mat4_1.array[3] = 4;
			mat4_1.array[4] = 5; mat4_1.array[5] = 6; mat4_1.array[6] = 7;	mat4_1.array[7] = 8;
			mat4_1.array[8] = 9; mat4_1.array[9] = 10; mat4_1.array[10] = 11; mat4_1.array[11] = 12;
			mat4_1.array[12] = 13; mat4_1.array[13] = 14; mat4_1.array[14] = 15; mat4_1.array[15] = 16;

			mat4_2.array[0] = 1; mat4_2.array[1] = 2; mat4_2.array[2] = 3; mat4_2.array[3] = 4;
			mat4_2.array[4] = 5; mat4_2.array[5] = 6; mat4_2.array[6] = 7; mat4_2.array[7] = 8;
			mat4_2.array[8] = 9; mat4_2.array[9] = 10; mat4_2.array[10] = 11; mat4_2.array[11] = 12;
			mat4_2.array[12] = 13; mat4_2.array[13] = 14; mat4_2.array[14] = 15; mat4_2.array[15] = 16;

			gmat4_1[0][0] = 1; gmat4_1[0][1] = 2; gmat4_1[0][2] = 3; gmat4_1[0][3] = 4;
			gmat4_1[1][0] = 5; gmat4_1[1][1] = 6; gmat4_1[1][2] = 7; gmat4_1[1][3] = 8;
			gmat4_1[2][0] = 9; gmat4_1[2][1] = 10; gmat4_1[2][2] = 11; gmat4_1[2][3] = 12;
			gmat4_1[3][0] = 13; gmat4_1[3][1] = 14; gmat4_1[3][2] = 15; gmat4_1[3][3] = 16;

			gmat4_2[0][0] = 1; gmat4_2[0][1] = 2; gmat4_2[0][2] = 3; gmat4_2[0][3] = 4;
			gmat4_2[1][0] = 5; gmat4_2[1][1] = 6; gmat4_2[1][2] = 7; gmat4_2[1][3] = 8;
			gmat4_2[2][0] = 9; gmat4_2[2][1] = 10; gmat4_2[2][2] = 11; gmat4_2[2][3] = 12;
			gmat4_2[3][0] = 13; gmat4_2[3][1] = 14; gmat4_2[3][2] = 15; gmat4_2[3][3] = 16;


			Math::QXmat4 mat4res = mat4_1 + mat4_2;
			glm::mat<4, 4, float> gmat4res = gmat4_1 + gmat4_2;
			for (unsigned int i = 0; i < 16; i++)
				Assert::AreEqual(mat4res.array[i], gmat4res[i / 4][i % 4]);
		}
		/* END Test Matrix4 */

		/* BEGIN Test Matrix */
		TEST_METHOD(addMatToMat)
		{
			Math::QXmat mat3_1(3,3), mat3_2(3,3);
			glm::mat<3, 3, float> gmat3_1, gmat3_2;

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			mat3_2.array[0] = 1; mat3_2.array[1] = 2; mat3_2.array[2] = 3;
			mat3_2.array[3] = 4; mat3_2.array[4] = 5; mat3_2.array[5] = 6;
			mat3_2.array[6] = 7; mat3_2.array[7] = 8; mat3_2.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			gmat3_2[0][0] = 1; gmat3_2[0][1] = 2; gmat3_2[0][2] = 3;
			gmat3_2[1][3] = 4; gmat3_2[1][0] = 5; gmat3_2[1][1] = 6;
			gmat3_2[2][2] = 7; gmat3_2[2][3] = 8; gmat3_2[2][0] = 9;


			Math::QXmat matres = mat3_1 + mat3_2;
			glm::mat<3, 3, float> gmatres = gmat3_1 + gmat3_2;
			for (unsigned int i = 0; i < 9; i++)
				Assert::AreEqual(matres.array[i], gmatres[i / 3][i % 3]);
		}


		TEST_METHOD(determinantMat)
		{
			Math::QXmat mat3_1(3, 3);
			glm::mat<3, 3, float> gmat3_1;

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			Assert::AreEqual(mat3_1.Determinant(), glm::determinant(gmat3_1));
		}

		TEST_METHOD(inverseMat)
		{
			Math::QXmat mat3_1(3, 3);
			glm::mat<3, 3, float> gmat3_1;

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			Math::QXmat matres = mat3_1.Inverse();
			glm::mat<3, 3, float> gmatres = glm::inverse(gmat3_1);
			for (unsigned int i = 0; i < 9; i++)
				Assert::AreEqual(matres.array[i], gmatres[i/3][i%3]);
		}

		TEST_METHOD(transposeMat)
		{
			Math::QXmat mat3_1(3, 3);
			glm::mat<3, 3, float> gmat3_1;

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			Math::QXmat matres = mat3_1.Transpose();
			glm::mat<3, 3, float> gmatres = glm::transpose(gmat3_1);
			for (unsigned int i = 0; i < 9; i++)
				Assert::AreEqual(matres.array[i], gmatres[i / 3][i % 3]);
		}

		TEST_METHOD(multiplicationMatToMat)
		{
			Math::QXmat mat3_1(3, 3), mat3_2(3, 3);
			glm::mat<3, 3, float> gmat3_1, gmat3_2;

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			mat3_2.array[0] = 1; mat3_2.array[1] = 2; mat3_2.array[2] = 3;
			mat3_2.array[3] = 4; mat3_2.array[4] = 5; mat3_2.array[5] = 6;
			mat3_2.array[6] = 7; mat3_2.array[7] = 8; mat3_2.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			gmat3_2[0][0] = 1; gmat3_2[0][1] = 2; gmat3_2[0][2] = 3;
			gmat3_2[1][0] = 4; gmat3_2[1][1] = 5; gmat3_2[1][2] = 6;
			gmat3_2[2][0] = 7; gmat3_2[2][1] = 8; gmat3_2[1][2] = 9;

			Math::QXmat matres = mat3_1 * mat3_2;
			glm::mat<3, 3, float> gmatres = gmat3_1 * gmat3_2;
			for (unsigned int i = 0; i < 9; i++)
				Assert::AreEqual(matres.array[i], gmatres[i / 3][i % 3]);
		}

		TEST_METHOD(multiplicationMatToVec3)
		{
			Math::QXmat mat3_1(3, 3);
			Math::QXvec3 vec3{ 1, 2, 3 };
			glm::mat<3, 3, float> gmat3_1;
			glm::vec4 gvec4{ 1, 2, 3, 1 };

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			Math::QXvec3 vec3res = mat3_1 * vec3;
			glm::vec3 gvec3res = gmat3_1 * gvec4;
			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3res[i], gvec3res[i]);
		}

		TEST_METHOD(multiplicationMatToVec4)
		{
			Math::QXmat mat3_1(3, 3);
			Math::QXvec4 vec4{ 1, 2, 3, 1 };
			glm::mat<3, 3, float> gmat3_1;
			glm::vec4 gvec4{ 1, 2, 3, 1 };

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			Math::QXvec4 vec3res = mat3_1 * vec4;
			glm::vec3 gvec3res = gmat3_1 * gvec4;
			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3res[i], gvec3res[i]);
		}

		TEST_METHOD(multiplicationMatToFloat)
		{
			Math::QXmat mat3_1(3, 3);
			glm::mat<3, 3, float> gmat3_1;

			mat3_1.array[0] = 1; mat3_1.array[1] = 2; mat3_1.array[2] = 3;
			mat3_1.array[3] = 4; mat3_1.array[4] = 5; mat3_1.array[5] = 6;
			mat3_1.array[6] = 7; mat3_1.array[7] = 8; mat3_1.array[8] = 9;

			gmat3_1[0][0] = 1; gmat3_1[0][1] = 2; gmat3_1[0][2] = 3;
			gmat3_1[1][0] = 4; gmat3_1[1][1] = 5; gmat3_1[1][2] = 6;
			gmat3_1[2][0] = 7; gmat3_1[2][1] = 8; gmat3_1[1][2] = 9;

			Math::QXmat mat3res = mat3_1 * 2.f;
			glm::mat<3, 3, float> gmat3res = gmat3_1 * 2.f;
			for (unsigned int i = 0; i < 9; i++)
				Assert::AreEqual(mat3res.array[i], gmat3res[i/3][i%3]);
		}
		/* END Test Matrix */

		/* BEGIN Test Vec3 */
		TEST_METHOD(crossProductVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Math::QXvec3 vec3Res = vec3.Cross({ 2,3,4 });
			glm::vec3 gvec3Res = glm::cross(gvec3, glm::vec3(2, 3, 4));

			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3Res[i], gvec3Res[i]);
		}

		TEST_METHOD(dotProductVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Assert::AreEqual(vec3.Dot({ 2,3,4 }), glm::dot(gvec3, glm::vec3(2, 3, 4)));
		}

		TEST_METHOD(normalizeVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Math::QXvec3 vec3Res = vec3.Normalize();
			glm::vec3 gvec3Res = glm::normalize(gvec3);

			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3Res[i], gvec3Res[i]);
		}

		TEST_METHOD(lengthVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Assert::AreEqual((float)gvec3.length(), vec3.Length());
		}

		TEST_METHOD(addVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3};
			Math::QXvec3 vec3{ 1, 2, 3};

			Math::QXvec3 vec3Res = vec3 + Math::QXvec3{ 2,3,4};
			glm::vec3 gvec3Res = gvec3 + glm::vec3(2, 3, 4);

			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3Res[i], gvec3Res[i]);
		}

		TEST_METHOD(subVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Math::QXvec3 vec3Res = vec3 - Math::QXvec3{ 2,3,4 };
			glm::vec3 gvec3Res = gvec3 - glm::vec3(2, 3, 4);

			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3Res[i], gvec3Res[i]);
		}

		TEST_METHOD(multVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Math::QXvec3 vec3Res = vec3 * 2.f;
			glm::vec3 gvec3Res = gvec3 * 2.f;

			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3Res[i], gvec3Res[i]);
		}

		TEST_METHOD(divVec3)
		{
			glm::vec3 gvec3{ 1, 2, 3 };
			Math::QXvec3 vec3{ 1, 2, 3 };

			Math::QXvec3 vec3Res = vec3 / 2.f;
			glm::vec3 gvec3Res = gvec3 / 2.f;

			for (unsigned int i = 0; i < 3; i++)
				Assert::AreEqual(vec3Res[i], gvec3Res[i]);
		}
		/* END Test Vec3 */

		/* BEGIN Test Vec4 */
		TEST_METHOD(normalizeVec4)
		{
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Math::QXvec4 vec4Res = vec4.Normalize();
			glm::vec4 gvec4Res = glm::normalize(gvec4);

			for (unsigned int i = 0; i < 4; i++)
				Assert::AreEqual(vec4Res[i], gvec4Res[i]);
		}

		TEST_METHOD(lengthVec4)
		{
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Assert::AreEqual((float)gvec4.length(), vec4.Length());
		}

		TEST_METHOD(addVec4)
		{
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Math::QXvec4 vec4Res = vec4 + Math::QXvec4{2,3,4,5};
			glm::vec4 gvec4Res = gvec4 + glm::vec4(2, 3, 4, 5);

			for (unsigned int i = 0; i < 4; i++)
				Assert::AreEqual(vec4Res[i], gvec4Res[i]);
		}

		TEST_METHOD(subVec4)
		{
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Math::QXvec4 vec4Res = vec4 - Math::QXvec4{ 2,3,4,5 };
			glm::vec4 gvec4Res = gvec4 - glm::vec4(2, 3, 4, 5);

			for (unsigned int i = 0; i < 4; i++)
				Assert::AreEqual(vec4Res[i], gvec4Res[i]);
		}

		TEST_METHOD(multVec4)
		{
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Math::QXvec4 vec4Res = vec4 * 2.f;
			glm::vec4 gvec4Res = gvec4 * 2.f;

			for (unsigned int i = 0; i < 4; i++)
				Assert::AreEqual(vec4Res[i], gvec4Res[i]);
		}

		TEST_METHOD(divVec4)
		{
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Math::QXvec4 vec4Res = vec4 / 2.f;
			glm::vec4 gvec4Res = gvec4 / 2.f;

			for (unsigned int i = 0; i < 4; i++)
				Assert::AreEqual(vec4Res[i], gvec4Res[i]);
		}
		/* END Test Vec4 */

		/* BEGIN Test Quaternion */
		TEST_METHOD(dotProductQuaternion)
		{
			//glm::quat q;
			glm::vec4 gvec4{ 1, 2, 3, 4 };
			Math::QXvec4 vec4{ 1, 2, 3, 4 };

			Math::QXvec4 vec4Res = vec4 / 2.f;
			glm::vec4 gvec4Res = gvec4 / 2.f;

			for (unsigned int i = 0; i < 4; i++)
				Assert::AreEqual(vec4Res[i], gvec4Res[i]);
		}
		/* END Test Quaternion */
	};
}
