import { Component, OnInit, Input, OnChanges } from '@angular/core';
import { UserService } from 'src/app/service/user.service';
import { UtilService } from 'src/app/service/util.service';
import { FileService } from 'src/app/service/file.service';
import { RepublicaService } from 'src/app/service/republica.service';

@Component({
  selector: 'app-profile-republica',
  templateUrl: './profile-republica.component.html',
  styleUrls: ['./profile-republica.component.css']
})
export class ProfileRepublicaComponent implements OnInit, OnChanges {

  @Input("profile") profile : any = { }

  personalidade: any = {
    abertura: 0,
    concordancia: 0,
    consciencia: 0,
    extroversao: 0,
    neuroticismo: 0
   }
   
   endereco: any = { }
   estados: any = [ ]
   fotoPerfil: File;

   repSendingPersonalidade = false;
   repMsgPersonalidade = '';
   repClassPersonalidade = '';

   repSendingForm = false;
   repMsgForm = '';
   repClassForm = '';

   repSendingCep = false;
   repMsgCEP = '';

  constructor(private _userService: UserService,
              private _utilService : UtilService,
              private _fileService : FileService,
              private _repService : RepublicaService) { }

  ngOnInit() {
    this._userService.checkCredentials();
    this.initEstados();
  }

  ngOnChanges() {
    this.configureMe();
  }

  initEstados() {
    this.estados = this._utilService.getEstadosBrasileiros();
  }

  configureMe() {
    if (this.profile.endereco != null)  this.endereco = this.profile.endereco;
    
    if (this.profile.perfil && this.profile.perfil.personalidade)
        this.personalidade = this.profile.perfil.personalidade;
  }

  
  changeCep() {
    this.repSendingCep = true;
    this._utilService.getAddressByCep(this.endereco.cep).subscribe((data : any) => {
      if (data != null) {
        this.endereco.logradouro = data.logradouro;
        this.endereco.complemento = data.complemento;
        this.endereco.bairro = data.bairro;
        this.endereco.uf = data.uf;
        this.endereco.cidade = data.localidade;
      }
      this.repSendingCep = false;
    }, err => {
      this.repSendingCep = false;
      this.repMsgCEP = "CEP inválido!";
    })
  }

  save() {
    this.repSendingForm = true;
    if (this.endereco != undefined) this.profile.endereco = this.endereco;
    
    this._userService.update(this.profile).subscribe(data => {
      this.profile = data;
      this.endereco = this.profile.endereco;

      this.repMsgForm = 'Suas informações foram salvas!';
      this.repClassForm = 'success'
      this.repSendingForm = false;
    }, err => {
      this.repMsgForm = 'Ocorreu um erro ao processar suas informações. Verifique seus dados e tente novamente!';
      this.repClassForm = 'danger'
      this.repSendingForm = false;
    })
  }

  upload(event) {
    if (event.target.files.length > 0) {
      let foto = event.target.files[0];
      this._fileService.upload(foto).subscribe((data:any) => {
        this.profile.fotoUrl = data.filename;
      })
    }
  }

  
  calcularPersonalidade() {
    this.repSendingPersonalidade = true;
    this._repService.calcularPersonalidade(this.profile).subscribe(data => {
      this.profile = data;
      this.configureMe();
      this.repSendingPersonalidade = false;
      this.repMsgPersonalidade = 'Personalidade atualizada!';
      this.repClassPersonalidade = 'success';
    }, err => {
      this.repSendingPersonalidade = false;
      this.repMsgPersonalidade = 'Ocorreu um erro. Verifique se você tem pelo menos 01 morador vinculado ao seu perfil para poder calcular sua personalidade!';
      this.repClassPersonalidade = 'danger';
    })
  }
}
