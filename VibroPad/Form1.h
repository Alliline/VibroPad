#pragma once
#pragma comment(lib, "XInput.lib")

#include "aboutDialog.h"

#define VIBRO_MAX	65535
#define VIBRO_HALF	32768

namespace VibroPad {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			pad_connected = false;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_stop;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	protected: 

	private:
		bool pad_connected;
		void definePad()
		{
			DWORD dwResult;    
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));

			// Simply get the state of the controller from XInput.
			dwResult = XInputGetState(0, &state);

			if(dwResult == ERROR_SUCCESS)
			{
				label_state->Text = L"Gamepad is connected.";
				if(!pad_connected)
				{
					pad_connected = true;
					vibratePad(VIBRO_MAX,0);
					timer_toggle_left->Enabled = true;
				}
			}
			else
			{
				label_state->Text = L"Gamepad is not connected.";
				pad_connected = false;
			}
		}
		void vibratePad(int l, int r)
		{
			XINPUT_VIBRATION vibration;
			ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));
			vibration.wLeftMotorSpeed = l; // use any value between 0-65535 here
			vibration.wRightMotorSpeed = r; // use any value between 0-65535 here
			XInputSetState(0, &vibration);
		}
	private: System::Windows::Forms::Label^  label_state;
	private: System::Windows::Forms::Button^  button_update;
	private: System::Windows::Forms::Label^  label_left;
	private: System::Windows::Forms::Label^  label_right;
	private: System::Windows::Forms::Button^  button_lmax;
	private: System::Windows::Forms::Button^  button_rmax;
	private: System::Windows::Forms::Timer^  timer_toggle_left;
	private: System::Windows::Forms::Timer^  timer_vibroOff;
	private: System::Windows::Forms::NumericUpDown^  left_control;
	private: System::Windows::Forms::NumericUpDown^  right_control;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label_state = (gcnew System::Windows::Forms::Label());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->label_left = (gcnew System::Windows::Forms::Label());
			this->label_right = (gcnew System::Windows::Forms::Label());
			this->button_lmax = (gcnew System::Windows::Forms::Button());
			this->button_rmax = (gcnew System::Windows::Forms::Button());
			this->timer_toggle_left = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer_vibroOff = (gcnew System::Windows::Forms::Timer(this->components));
			this->left_control = (gcnew System::Windows::Forms::NumericUpDown());
			this->right_control = (gcnew System::Windows::Forms::NumericUpDown());
			this->button_stop = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->left_control))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->right_control))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_state
			// 
			this->label_state->AutoSize = true;
			this->label_state->Location = System::Drawing::Point(13, 30);
			this->label_state->Name = L"label_state";
			this->label_state->Size = System::Drawing::Size(138, 13);
			this->label_state->TabIndex = 0;
			this->label_state->Text = L"Gamepad is not connected.";
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(157, 25);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(75, 23);
			this->button_update->TabIndex = 1;
			this->button_update->Text = L"Update";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &Form1::button_update_Click);
			// 
			// label_left
			// 
			this->label_left->AutoSize = true;
			this->label_left->Location = System::Drawing::Point(13, 67);
			this->label_left->Name = L"label_left";
			this->label_left->Size = System::Drawing::Size(89, 13);
			this->label_left->TabIndex = 3;
			this->label_left->Text = L"Left motor power:";
			// 
			// label_right
			// 
			this->label_right->AutoSize = true;
			this->label_right->Location = System::Drawing::Point(13, 97);
			this->label_right->Name = L"label_right";
			this->label_right->Size = System::Drawing::Size(96, 13);
			this->label_right->TabIndex = 5;
			this->label_right->Text = L"Right motor power:";
			// 
			// button_lmax
			// 
			this->button_lmax->Location = System::Drawing::Point(188, 62);
			this->button_lmax->Name = L"button_lmax";
			this->button_lmax->Size = System::Drawing::Size(44, 23);
			this->button_lmax->TabIndex = 6;
			this->button_lmax->Text = L"max";
			this->button_lmax->UseVisualStyleBackColor = true;
			this->button_lmax->Click += gcnew System::EventHandler(this, &Form1::button_lmax_Click);
			// 
			// button_rmax
			// 
			this->button_rmax->Location = System::Drawing::Point(188, 91);
			this->button_rmax->Name = L"button_rmax";
			this->button_rmax->Size = System::Drawing::Size(44, 23);
			this->button_rmax->TabIndex = 7;
			this->button_rmax->Text = L"max";
			this->button_rmax->UseVisualStyleBackColor = true;
			this->button_rmax->Click += gcnew System::EventHandler(this, &Form1::button_rmax_Click);
			// 
			// timer_toggle_left
			// 
			this->timer_toggle_left->Interval = 500;
			this->timer_toggle_left->Tick += gcnew System::EventHandler(this, &Form1::toggle_left);
			// 
			// timer_vibroOff
			// 
			this->timer_vibroOff->Tick += gcnew System::EventHandler(this, &Form1::vibroOff);
			// 
			// left_control
			// 
			this->left_control->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->left_control->Location = System::Drawing::Point(122, 65);
			this->left_control->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->left_control->Name = L"left_control";
			this->left_control->Size = System::Drawing::Size(60, 20);
			this->left_control->TabIndex = 8;
			this->left_control->ValueChanged += gcnew System::EventHandler(this, &Form1::button_update_Click);
			// 
			// right_control
			// 
			this->right_control->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->right_control->Location = System::Drawing::Point(122, 95);
			this->right_control->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->right_control->Name = L"right_control";
			this->right_control->Size = System::Drawing::Size(60, 20);
			this->right_control->TabIndex = 9;
			this->right_control->ValueChanged += gcnew System::EventHandler(this, &Form1::button_update_Click);
			// 
			// button_stop
			// 
			this->button_stop->Location = System::Drawing::Point(16, 132);
			this->button_stop->Name = L"button_stop";
			this->button_stop->Size = System::Drawing::Size(214, 23);
			this->button_stop->TabIndex = 10;
			this->button_stop->Text = L"Stop";
			this->button_stop->UseVisualStyleBackColor = true;
			this->button_stop->Click += gcnew System::EventHandler(this, &Form1::button_stop_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(242, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"&About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(242, 161);
			this->Controls->Add(this->button_stop);
			this->Controls->Add(this->right_control);
			this->Controls->Add(this->left_control);
			this->Controls->Add(this->button_rmax);
			this->Controls->Add(this->button_lmax);
			this->Controls->Add(this->label_right);
			this->Controls->Add(this->label_left);
			this->Controls->Add(this->button_update);
			this->Controls->Add(this->label_state);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"VibroPad v1.0";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->left_control))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->right_control))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				definePad();
			 }
	
	//TIMERS!!!
	private: System::Void toggle_left(System::Object^  sender, System::EventArgs^  e) 
		 {
			timer_toggle_left->Enabled = false;
			vibratePad(0,VIBRO_MAX);
			timer_vibroOff->Enabled = true;
		 }
	private: System::Void vibroOff(System::Object^  sender, System::EventArgs^  e) 
		 {
			timer_vibroOff->Enabled = false;
			vibratePad(0,0);
		 }
	//=========
	private: System::Void button_update_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 definePad();
			 vibratePad((int)left_control->Value,(int)right_control->Value);
		 }
	private: System::Void button_lmax_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 left_control->Value = VIBRO_MAX;
		 }
	private: System::Void button_rmax_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			right_control->Value = VIBRO_MAX;
		}
	private: System::Void button_stop_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			left_control->Value = 0;
			right_control->Value = 0;
			vibratePad(0,0);
		}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			aboutDialog^ dlg1 = gcnew aboutDialog();
			dlg1->ShowDialog();
		 }
};
}

