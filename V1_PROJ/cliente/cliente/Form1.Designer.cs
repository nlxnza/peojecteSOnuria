namespace WindowsFormsApplication1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.conectar = new System.Windows.Forms.Button();
            this.desconectar = new System.Windows.Forms.Button();
            this.user = new System.Windows.Forms.TextBox();
            this.usuario = new System.Windows.Forms.Label();
            this.contraseña = new System.Windows.Forms.Label();
            this.pass = new System.Windows.Forms.TextBox();
            this.iniciars = new System.Windows.Forms.Button();
            this.register = new System.Windows.Forms.Button();
            this.ganador = new System.Windows.Forms.RadioButton();
            this.enviar = new System.Windows.Forms.Button();
            this.datos = new System.Windows.Forms.RadioButton();
            this.recovery = new System.Windows.Forms.RadioButton();
            this.nombre = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // conectar
            // 
            this.conectar.Location = new System.Drawing.Point(22, 21);
            this.conectar.Name = "conectar";
            this.conectar.Size = new System.Drawing.Size(100, 49);
            this.conectar.TabIndex = 0;
            this.conectar.Text = "conectar";
            this.conectar.UseVisualStyleBackColor = true;
            this.conectar.Click += new System.EventHandler(this.button1_Click);
            // 
            // desconectar
            // 
            this.desconectar.Location = new System.Drawing.Point(329, 21);
            this.desconectar.Name = "desconectar";
            this.desconectar.Size = new System.Drawing.Size(115, 49);
            this.desconectar.TabIndex = 2;
            this.desconectar.Text = "desconectar";
            this.desconectar.UseVisualStyleBackColor = true;
            this.desconectar.Click += new System.EventHandler(this.button2_Click);
            // 
            // user
            // 
            this.user.Location = new System.Drawing.Point(179, 34);
            this.user.Name = "user";
            this.user.Size = new System.Drawing.Size(100, 22);
            this.user.TabIndex = 3;
            // 
            // usuario
            // 
            this.usuario.AutoSize = true;
            this.usuario.Location = new System.Drawing.Point(176, 9);
            this.usuario.Name = "usuario";
            this.usuario.Size = new System.Drawing.Size(55, 17);
            this.usuario.TabIndex = 4;
            this.usuario.Text = "usuario";
            this.usuario.Click += new System.EventHandler(this.label1_Click);
            // 
            // contraseña
            // 
            this.contraseña.AutoSize = true;
            this.contraseña.Location = new System.Drawing.Point(176, 70);
            this.contraseña.Name = "contraseña";
            this.contraseña.Size = new System.Drawing.Size(79, 17);
            this.contraseña.TabIndex = 5;
            this.contraseña.Text = "contraseña";
            // 
            // pass
            // 
            this.pass.Location = new System.Drawing.Point(179, 90);
            this.pass.Name = "pass";
            this.pass.Size = new System.Drawing.Size(100, 22);
            this.pass.TabIndex = 6;
            // 
            // iniciars
            // 
            this.iniciars.Location = new System.Drawing.Point(22, 145);
            this.iniciars.Name = "iniciars";
            this.iniciars.Size = new System.Drawing.Size(129, 56);
            this.iniciars.TabIndex = 7;
            this.iniciars.Text = "Iniciar Sesion";
            this.iniciars.UseVisualStyleBackColor = true;
            this.iniciars.Click += new System.EventHandler(this.iniciars_Click);
            // 
            // register
            // 
            this.register.Location = new System.Drawing.Point(364, 90);
            this.register.Name = "register";
            this.register.Size = new System.Drawing.Size(94, 58);
            this.register.TabIndex = 8;
            this.register.Text = "Registrate";
            this.register.UseVisualStyleBackColor = true;
            this.register.Click += new System.EventHandler(this.register_Click);
            // 
            // ganador
            // 
            this.ganador.AutoSize = true;
            this.ganador.Location = new System.Drawing.Point(179, 143);
            this.ganador.Name = "ganador";
            this.ganador.Size = new System.Drawing.Size(110, 21);
            this.ganador.TabIndex = 9;
            this.ganador.TabStop = true;
            this.ganador.Text = "TOP SCORE";
            this.ganador.UseVisualStyleBackColor = true;
            this.ganador.CheckedChanged += new System.EventHandler(this.ganador_CheckedChanged);
            // 
            // enviar
            // 
            this.enviar.Location = new System.Drawing.Point(179, 270);
            this.enviar.Name = "enviar";
            this.enviar.Size = new System.Drawing.Size(100, 37);
            this.enviar.TabIndex = 12;
            this.enviar.Text = "enviar";
            this.enviar.UseVisualStyleBackColor = true;
            this.enviar.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // datos
            // 
            this.datos.AutoSize = true;
            this.datos.Location = new System.Drawing.Point(169, 180);
            this.datos.Name = "datos";
            this.datos.Size = new System.Drawing.Size(133, 21);
            this.datos.TabIndex = 13;
            this.datos.TabStop = true;
            this.datos.Text = "Datos jugadores";
            this.datos.UseVisualStyleBackColor = true;
            // 
            // recovery
            // 
            this.recovery.AutoSize = true;
            this.recovery.Location = new System.Drawing.Point(111, 219);
            this.recovery.Name = "recovery";
            this.recovery.Size = new System.Drawing.Size(168, 21);
            this.recovery.TabIndex = 14;
            this.recovery.TabStop = true;
            this.recovery.Text = "Recovery Passwor -->";
            this.recovery.UseVisualStyleBackColor = true;
            // 
            // nombre
            // 
            this.nombre.Location = new System.Drawing.Point(285, 219);
            this.nombre.Name = "nombre";
            this.nombre.Size = new System.Drawing.Size(100, 22);
            this.nombre.TabIndex = 15;
            this.nombre.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(470, 334);
            this.Controls.Add(this.nombre);
            this.Controls.Add(this.recovery);
            this.Controls.Add(this.datos);
            this.Controls.Add(this.enviar);
            this.Controls.Add(this.ganador);
            this.Controls.Add(this.register);
            this.Controls.Add(this.iniciars);
            this.Controls.Add(this.pass);
            this.Controls.Add(this.contraseña);
            this.Controls.Add(this.usuario);
            this.Controls.Add(this.user);
            this.Controls.Add(this.desconectar);
            this.Controls.Add(this.conectar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button conectar;
        private System.Windows.Forms.Button desconectar;
        private System.Windows.Forms.TextBox user;
        private System.Windows.Forms.Label usuario;
        private System.Windows.Forms.Label contraseña;
        private System.Windows.Forms.TextBox pass;
        private System.Windows.Forms.Button iniciars;
        private System.Windows.Forms.Button register;
        private System.Windows.Forms.RadioButton ganador;
        private System.Windows.Forms.Button enviar;
        private System.Windows.Forms.RadioButton datos;
        private System.Windows.Forms.RadioButton recovery;
        private System.Windows.Forms.TextBox nombre;
    }
}

