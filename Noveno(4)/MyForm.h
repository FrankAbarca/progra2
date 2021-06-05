#pragma once
#include "Controladora.h"
#include "Archivo_Texto.h"
namespace Octavo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			obj_controladora = new Controladora();
			Archivo_Texto* miarchivotxt = new Archivo_Texto();
			vector<string> datosleido = miarchivotxt->LeerdesdeArchivo("datosmonigote.txt");
			imagenmonigote = gcnew Bitmap(gcnew String(datosleido[0].c_str()));
			imagenasteroide = gcnew Bitmap(gcnew String(datosleido[1].c_str()));
			delete miarchivotxt;
			obj_controladora->Init(imagenmonigote,imagenasteroide);  // puntero this: puntero por defecto a la misma clase
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete obj_controladora,imagenmonigote, imagenasteroide;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Controladora* obj_controladora;
		Bitmap^ imagenmonigote;
		Bitmap^ imagenasteroide;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 552);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();  // Graphics Original
		/* CREACION DEL BUFFER GRAPHICS*/
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bfg = espacio->Allocate(g, this->ClientRectangle);
		//bfg->Graphics->Clear(Color::Black); // BORRAR EL BUFFER
		obj_controladora->Run(bfg->Graphics,imagenmonigote,imagenasteroide);// DIBUJAR EN EL BUFER
		bfg->Render(g); // COPIAR EL CONTENIDO DEL BUFFER EN EL GRAPHICS ORIGINAL
		delete bfg,espacio,g; //BORRAR TODO
		timer1->Enabled = !obj_controladora->Retornar_termino();

	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyData == Keys::Left)  // tecla izquierda
			obj_controladora->Mover_Monigote(movimiento::izquierda);
		if (e->KeyData == Keys::Right)  // tecla derecha
			obj_controladora->Mover_Monigote(movimiento::derecha);
		if (e->KeyData == Keys::Down)  // tecla abajo
			obj_controladora->Mover_Monigote(movimiento::abajo);
		if (e->KeyData == Keys::Up)  // tecla arriba
			obj_controladora->Mover_Monigote(movimiento::arriba);
		if (e->KeyData == Keys::Space)
			obj_controladora->Disparar();

	}
	};
}
