// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "data"
#define AUTOTB_TVIN_data  "../tv/cdatafile/c.forw_back.autotvin_data.dat"
#define AUTOTB_TVOUT_data  "../tv/cdatafile/c.forw_back.autotvout_data.dat"
// wrapc file define: "flag"
#define AUTOTB_TVIN_flag  "../tv/cdatafile/c.forw_back.autotvin_flag.dat"
// wrapc file define: "in_r"
#define AUTOTB_TVIN_in_r  "../tv/cdatafile/c.forw_back.autotvin_in_r.dat"
// wrapc file define: "conv1"
#define AUTOTB_TVIN_conv1  "../tv/cdatafile/c.forw_back.autotvin_conv1.dat"
// wrapc file define: "conv2"
#define AUTOTB_TVIN_conv2  "../tv/cdatafile/c.forw_back.autotvin_conv2.dat"
// wrapc file define: "conv3"
#define AUTOTB_TVIN_conv3  "../tv/cdatafile/c.forw_back.autotvin_conv3.dat"
// wrapc file define: "fc1"
#define AUTOTB_TVIN_fc1  "../tv/cdatafile/c.forw_back.autotvin_fc1.dat"
// wrapc file define: "fc2"
#define AUTOTB_TVIN_fc2  "../tv/cdatafile/c.forw_back.autotvin_fc2.dat"
// wrapc file define: "fc3"
#define AUTOTB_TVIN_fc3  "../tv/cdatafile/c.forw_back.autotvin_fc3.dat"
// wrapc file define: "out_r"
#define AUTOTB_TVIN_out_r  "../tv/cdatafile/c.forw_back.autotvin_out_r.dat"
// wrapc file define: "label_r"
#define AUTOTB_TVIN_label_r  "../tv/cdatafile/c.forw_back.autotvin_label_r.dat"
// wrapc file define: "lr"
#define AUTOTB_TVIN_lr  "../tv/cdatafile/c.forw_back.autotvin_lr.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "data"
#define AUTOTB_TVOUT_PC_data  "../tv/rtldatafile/rtl.forw_back.autotvout_data.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			data_depth = 0;
			flag_depth = 0;
			in_r_depth = 0;
			conv1_depth = 0;
			conv2_depth = 0;
			conv3_depth = 0;
			fc1_depth = 0;
			fc2_depth = 0;
			fc3_depth = 0;
			out_r_depth = 0;
			label_r_depth = 0;
			lr_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{data " << data_depth << "}\n";
			total_list << "{flag " << flag_depth << "}\n";
			total_list << "{in_r " << in_r_depth << "}\n";
			total_list << "{conv1 " << conv1_depth << "}\n";
			total_list << "{conv2 " << conv2_depth << "}\n";
			total_list << "{conv3 " << conv3_depth << "}\n";
			total_list << "{fc1 " << fc1_depth << "}\n";
			total_list << "{fc2 " << fc2_depth << "}\n";
			total_list << "{fc3 " << fc3_depth << "}\n";
			total_list << "{out_r " << out_r_depth << "}\n";
			total_list << "{label_r " << label_r_depth << "}\n";
			total_list << "{lr " << lr_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int data_depth;
		int flag_depth;
		int in_r_depth;
		int conv1_depth;
		int conv2_depth;
		int conv3_depth;
		int fc1_depth;
		int fc2_depth;
		int fc3_depth;
		int out_r_depth;
		int label_r_depth;
		int lr_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern "C" void forw_back (
int flag,
float* in,
float* conv1,
float* conv2,
float* conv3,
float* fc1,
float* fc2,
float* fc3,
float* out,
int label,
float* lr);

extern "C" void AESL_WRAP_forw_back (
int flag,
float* in,
float* conv1,
float* conv2,
float* conv3,
float* fc1,
float* fc2,
float* fc3,
float* out,
int label,
float* lr)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "data"
		aesl_fh.read(AUTOTB_TVOUT_PC_data, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_data, AESL_token); // data

			sc_bv<32> *data_pc_buffer = new sc_bv<32>[288];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'data', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'data', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					data_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_data, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_data))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: data
				{
					// bitslice(31, 0)
					// {
						// celement: in(31, 0)
						// {
							sc_lv<32>* in_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: conv1(31, 0)
						// {
							sc_lv<32>* conv1_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: conv2(31, 0)
						// {
							sc_lv<32>* conv2_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: conv3(31, 0)
						// {
							sc_lv<32>* conv3_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: fc1(31, 0)
						// {
							sc_lv<32>* fc1_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: fc2(31, 0)
						// {
							sc_lv<32>* fc2_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: fc3(31, 0)
						// {
							sc_lv<32>* fc3_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: out(31, 0)
						// {
							sc_lv<32>* out_lv0_0_31_1 = new sc_lv<32>[288];
						// }
						// celement: lr(31, 0)
						// {
							sc_lv<32>* lr_lv0_0_31_1 = new sc_lv<32>[288];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: in(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								hls_map_index++;
							}
						}
						// celement: conv1(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(conv1[0]) != NULL) // check the null address if the c port is array or others
								{
									conv1_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: conv2(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(conv2[0]) != NULL) // check the null address if the c port is array or others
								{
									conv2_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: conv3(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(conv3[0]) != NULL) // check the null address if the c port is array or others
								{
									conv3_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: fc1(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(fc1[0]) != NULL) // check the null address if the c port is array or others
								{
									fc1_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: fc2(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(fc2[0]) != NULL) // check the null address if the c port is array or others
								{
									fc2_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: fc3(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(fc3[0]) != NULL) // check the null address if the c port is array or others
								{
									fc3_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: out(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(out[0]) != NULL) // check the null address if the c port is array or others
								{
									out_lv0_0_31_1[hls_map_index].range(31, 0) = sc_bv<32>(data_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
						// celement: lr(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								hls_map_index++;
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: in(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : in[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : in[0]
								// output_left_conversion : *(int*)&in[i_0]
								// output_type_conversion : (in_lv0_0_31_1[hls_map_index]).to_uint64()
								hls_map_index++;
							}
						}
						// celement: conv1(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : conv1[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : conv1[0]
								// output_left_conversion : *(int*)&conv1[i_0]
								// output_type_conversion : (conv1_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(conv1[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&conv1[i_0] = (conv1_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: conv2(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : conv2[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : conv2[0]
								// output_left_conversion : *(int*)&conv2[i_0]
								// output_type_conversion : (conv2_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(conv2[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&conv2[i_0] = (conv2_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: conv3(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : conv3[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : conv3[0]
								// output_left_conversion : *(int*)&conv3[i_0]
								// output_type_conversion : (conv3_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(conv3[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&conv3[i_0] = (conv3_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: fc1(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : fc1[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : fc1[0]
								// output_left_conversion : *(int*)&fc1[i_0]
								// output_type_conversion : (fc1_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(fc1[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&fc1[i_0] = (fc1_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: fc2(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : fc2[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : fc2[0]
								// output_left_conversion : *(int*)&fc2[i_0]
								// output_type_conversion : (fc2_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(fc2[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&fc2[i_0] = (fc2_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: fc3(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : fc3[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : fc3[0]
								// output_left_conversion : *(int*)&fc3[i_0]
								// output_type_conversion : (fc3_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(fc3[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&fc3[i_0] = (fc3_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: out(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : out[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : out[0]
								// output_left_conversion : *(int*)&out[i_0]
								// output_type_conversion : (out_lv0_0_31_1[hls_map_index]).to_uint64()
								if (&(out[0]) != NULL) // check the null address if the c port is array or others
								{
									*(int*)&out[i_0] = (out_lv0_0_31_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
						// celement: lr(31, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : lr[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : lr[0]
								// output_left_conversion : *(int*)&lr[i_0]
								// output_type_conversion : (lr_lv0_0_31_1[hls_map_index]).to_uint64()
								hls_map_index++;
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] data_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "data"
		char* tvin_data = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_data);
		char* tvout_data = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_data);

		// "flag"
		char* tvin_flag = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_flag);

		// "in_r"
		char* tvin_in_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_in_r);

		// "conv1"
		char* tvin_conv1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_conv1);

		// "conv2"
		char* tvin_conv2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_conv2);

		// "conv3"
		char* tvin_conv3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_conv3);

		// "fc1"
		char* tvin_fc1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_fc1);

		// "fc2"
		char* tvin_fc2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_fc2);

		// "fc3"
		char* tvin_fc3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_fc3);

		// "out_r"
		char* tvin_out_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_out_r);

		// "label_r"
		char* tvin_label_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_label_r);

		// "lr"
		char* tvin_lr = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_lr);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_data, tvin_data);

		sc_bv<32>* data_tvin_wrapc_buffer = new sc_bv<32>[288];

		// RTL Name: data
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: in(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : in[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : in[0]
						// regulate_c_name       : in
						// input_type_conversion : *(int*)&in[i_0]
						if (&(in[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> in_tmp_mem;
							in_tmp_mem = *(int*)&in[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = in_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: conv1(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : conv1[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : conv1[0]
						// regulate_c_name       : conv1
						// input_type_conversion : *(int*)&conv1[i_0]
						if (&(conv1[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> conv1_tmp_mem;
							conv1_tmp_mem = *(int*)&conv1[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = conv1_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: conv2(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : conv2[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : conv2[0]
						// regulate_c_name       : conv2
						// input_type_conversion : *(int*)&conv2[i_0]
						if (&(conv2[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> conv2_tmp_mem;
							conv2_tmp_mem = *(int*)&conv2[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = conv2_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: conv3(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : conv3[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : conv3[0]
						// regulate_c_name       : conv3
						// input_type_conversion : *(int*)&conv3[i_0]
						if (&(conv3[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> conv3_tmp_mem;
							conv3_tmp_mem = *(int*)&conv3[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = conv3_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: fc1(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : fc1[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : fc1[0]
						// regulate_c_name       : fc1
						// input_type_conversion : *(int*)&fc1[i_0]
						if (&(fc1[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> fc1_tmp_mem;
							fc1_tmp_mem = *(int*)&fc1[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = fc1_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: fc2(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : fc2[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : fc2[0]
						// regulate_c_name       : fc2
						// input_type_conversion : *(int*)&fc2[i_0]
						if (&(fc2[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> fc2_tmp_mem;
							fc2_tmp_mem = *(int*)&fc2[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = fc2_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: fc3(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : fc3[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : fc3[0]
						// regulate_c_name       : fc3
						// input_type_conversion : *(int*)&fc3[i_0]
						if (&(fc3[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> fc3_tmp_mem;
							fc3_tmp_mem = *(int*)&fc3[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = fc3_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: out(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : out[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : out[0]
						// regulate_c_name       : out
						// input_type_conversion : *(int*)&out[i_0]
						if (&(out[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> out_tmp_mem;
							out_tmp_mem = *(int*)&out[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = out_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: lr(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : lr[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : lr[0]
						// regulate_c_name       : lr
						// input_type_conversion : *(int*)&lr[i_0]
						if (&(lr[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> lr_tmp_mem;
							lr_tmp_mem = *(int*)&lr[i_0];
							data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = lr_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 288; i++)
		{
			sprintf(tvin_data, "%s\n", (data_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_data, tvin_data);
		}

		tcl_file.set_num(288, &tcl_file.data_depth);
		sprintf(tvin_data, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_data, tvin_data);

		// release memory allocation
		delete [] data_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_flag, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_flag, tvin_flag);

		sc_bv<32> flag_tvin_wrapc_buffer;

		// RTL Name: flag
		{
			// bitslice(31, 0)
			{
				// celement: flag(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : flag
						// sub_1st_elem          : 
						// ori_name_1st_elem     : flag
						// regulate_c_name       : flag
						// input_type_conversion : flag
						if (&(flag) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> flag_tmp_mem;
							flag_tmp_mem = flag;
							flag_tvin_wrapc_buffer.range(31, 0) = flag_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_flag, "%s\n", (flag_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_flag, tvin_flag);
		}

		tcl_file.set_num(1, &tcl_file.flag_depth);
		sprintf(tvin_flag, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_flag, tvin_flag);

		// [[transaction]]
		sprintf(tvin_in_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_in_r, tvin_in_r);

		sc_bv<32> in_r_tvin_wrapc_buffer;

		// RTL Name: in_r
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_in_r, "%s\n", (in_r_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_in_r, tvin_in_r);
		}

		tcl_file.set_num(1, &tcl_file.in_r_depth);
		sprintf(tvin_in_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_in_r, tvin_in_r);

		// [[transaction]]
		sprintf(tvin_conv1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_conv1, tvin_conv1);

		sc_bv<32> conv1_tvin_wrapc_buffer;

		// RTL Name: conv1
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_conv1, "%s\n", (conv1_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_conv1, tvin_conv1);
		}

		tcl_file.set_num(1, &tcl_file.conv1_depth);
		sprintf(tvin_conv1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_conv1, tvin_conv1);

		// [[transaction]]
		sprintf(tvin_conv2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_conv2, tvin_conv2);

		sc_bv<32> conv2_tvin_wrapc_buffer;

		// RTL Name: conv2
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_conv2, "%s\n", (conv2_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_conv2, tvin_conv2);
		}

		tcl_file.set_num(1, &tcl_file.conv2_depth);
		sprintf(tvin_conv2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_conv2, tvin_conv2);

		// [[transaction]]
		sprintf(tvin_conv3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_conv3, tvin_conv3);

		sc_bv<32> conv3_tvin_wrapc_buffer;

		// RTL Name: conv3
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_conv3, "%s\n", (conv3_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_conv3, tvin_conv3);
		}

		tcl_file.set_num(1, &tcl_file.conv3_depth);
		sprintf(tvin_conv3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_conv3, tvin_conv3);

		// [[transaction]]
		sprintf(tvin_fc1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_fc1, tvin_fc1);

		sc_bv<32> fc1_tvin_wrapc_buffer;

		// RTL Name: fc1
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_fc1, "%s\n", (fc1_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_fc1, tvin_fc1);
		}

		tcl_file.set_num(1, &tcl_file.fc1_depth);
		sprintf(tvin_fc1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_fc1, tvin_fc1);

		// [[transaction]]
		sprintf(tvin_fc2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_fc2, tvin_fc2);

		sc_bv<32> fc2_tvin_wrapc_buffer;

		// RTL Name: fc2
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_fc2, "%s\n", (fc2_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_fc2, tvin_fc2);
		}

		tcl_file.set_num(1, &tcl_file.fc2_depth);
		sprintf(tvin_fc2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_fc2, tvin_fc2);

		// [[transaction]]
		sprintf(tvin_fc3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_fc3, tvin_fc3);

		sc_bv<32> fc3_tvin_wrapc_buffer;

		// RTL Name: fc3
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_fc3, "%s\n", (fc3_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_fc3, tvin_fc3);
		}

		tcl_file.set_num(1, &tcl_file.fc3_depth);
		sprintf(tvin_fc3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_fc3, tvin_fc3);

		// [[transaction]]
		sprintf(tvin_out_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_out_r, tvin_out_r);

		sc_bv<32> out_r_tvin_wrapc_buffer;

		// RTL Name: out_r
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_out_r, "%s\n", (out_r_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_out_r, tvin_out_r);
		}

		tcl_file.set_num(1, &tcl_file.out_r_depth);
		sprintf(tvin_out_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_out_r, tvin_out_r);

		// [[transaction]]
		sprintf(tvin_label_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_label_r, tvin_label_r);

		sc_bv<32> label_r_tvin_wrapc_buffer;

		// RTL Name: label_r
		{
			// bitslice(31, 0)
			{
				// celement: label(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : label
						// sub_1st_elem          : 
						// ori_name_1st_elem     : label
						// regulate_c_name       : label
						// input_type_conversion : label
						if (&(label) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> label_tmp_mem;
							label_tmp_mem = label;
							label_r_tvin_wrapc_buffer.range(31, 0) = label_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_label_r, "%s\n", (label_r_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_label_r, tvin_label_r);
		}

		tcl_file.set_num(1, &tcl_file.label_r_depth);
		sprintf(tvin_label_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_label_r, tvin_label_r);

		// [[transaction]]
		sprintf(tvin_lr, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_lr, tvin_lr);

		sc_bv<32> lr_tvin_wrapc_buffer;

		// RTL Name: lr
		{
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_lr, "%s\n", (lr_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_lr, tvin_lr);
		}

		tcl_file.set_num(1, &tcl_file.lr_depth);
		sprintf(tvin_lr, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_lr, tvin_lr);

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		forw_back(flag, in, conv1, conv2, conv3, fc1, fc2, fc3, out, label, lr);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_data, tvout_data);

		sc_bv<32>* data_tvout_wrapc_buffer = new sc_bv<32>[288];

		// RTL Name: data
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: in(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : in[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : in[0]
						// regulate_c_name       : in
						// input_type_conversion : *(int*)&in[i_0]
						if (&(in[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> in_tmp_mem;
							in_tmp_mem = *(int*)&in[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = in_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: conv1(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : conv1[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : conv1[0]
						// regulate_c_name       : conv1
						// input_type_conversion : *(int*)&conv1[i_0]
						if (&(conv1[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> conv1_tmp_mem;
							conv1_tmp_mem = *(int*)&conv1[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = conv1_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: conv2(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : conv2[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : conv2[0]
						// regulate_c_name       : conv2
						// input_type_conversion : *(int*)&conv2[i_0]
						if (&(conv2[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> conv2_tmp_mem;
							conv2_tmp_mem = *(int*)&conv2[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = conv2_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: conv3(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : conv3[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : conv3[0]
						// regulate_c_name       : conv3
						// input_type_conversion : *(int*)&conv3[i_0]
						if (&(conv3[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> conv3_tmp_mem;
							conv3_tmp_mem = *(int*)&conv3[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = conv3_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: fc1(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : fc1[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : fc1[0]
						// regulate_c_name       : fc1
						// input_type_conversion : *(int*)&fc1[i_0]
						if (&(fc1[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> fc1_tmp_mem;
							fc1_tmp_mem = *(int*)&fc1[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = fc1_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: fc2(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : fc2[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : fc2[0]
						// regulate_c_name       : fc2
						// input_type_conversion : *(int*)&fc2[i_0]
						if (&(fc2[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> fc2_tmp_mem;
							fc2_tmp_mem = *(int*)&fc2[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = fc2_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: fc3(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : fc3[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : fc3[0]
						// regulate_c_name       : fc3
						// input_type_conversion : *(int*)&fc3[i_0]
						if (&(fc3[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> fc3_tmp_mem;
							fc3_tmp_mem = *(int*)&fc3[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = fc3_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: out(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : out[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : out[0]
						// regulate_c_name       : out
						// input_type_conversion : *(int*)&out[i_0]
						if (&(out[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> out_tmp_mem;
							out_tmp_mem = *(int*)&out[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = out_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
				// celement: lr(31, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : lr[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : lr[0]
						// regulate_c_name       : lr
						// input_type_conversion : *(int*)&lr[i_0]
						if (&(lr[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> lr_tmp_mem;
							lr_tmp_mem = *(int*)&lr[i_0];
							data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = lr_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 288; i++)
		{
			sprintf(tvout_data, "%s\n", (data_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_data, tvout_data);
		}

		tcl_file.set_num(288, &tcl_file.data_depth);
		sprintf(tvout_data, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_data, tvout_data);

		// release memory allocation
		delete [] data_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "data"
		delete [] tvin_data;
		delete [] tvout_data;
		// release memory allocation: "flag"
		delete [] tvin_flag;
		// release memory allocation: "in_r"
		delete [] tvin_in_r;
		// release memory allocation: "conv1"
		delete [] tvin_conv1;
		// release memory allocation: "conv2"
		delete [] tvin_conv2;
		// release memory allocation: "conv3"
		delete [] tvin_conv3;
		// release memory allocation: "fc1"
		delete [] tvin_fc1;
		// release memory allocation: "fc2"
		delete [] tvin_fc2;
		// release memory allocation: "fc3"
		delete [] tvin_fc3;
		// release memory allocation: "out_r"
		delete [] tvin_out_r;
		// release memory allocation: "label_r"
		delete [] tvin_label_r;
		// release memory allocation: "lr"
		delete [] tvin_lr;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

