import { Component, OnInit, OnChanges, Input } from '@angular/core';
import { UniversidadeService } from 'src/app/service/universidade.service';
import { UtilService } from 'src/app/service/util.service';
import { UserService } from 'src/app/service/user.service';
import { FileService } from 'src/app/service/file.service';

@Component({
  selector: 'app-profile-estudante',
  templateUrl: './profile-estudante.component.html',
  styleUrls: ['./profile-estudante.component.css']
})
export class ProfileEstudanteComponent implements OnInit, OnChanges {

  @Input("profile") profile: any = { }
  
  personalidade: any = {}
  endereco: any = { }
  newUniversidade: any = { }
  universidades: any = [];
  
  profUniversidade: number = 0;
  estados: any = [];
  fotoPerfil: File;
  
  _republicas: any = [];

  errorCEP = '';

  callbackUpdateMessage = '';
  callbackUpdateClass = '';
  sending = false;

  constructor(private _userService : UserService,
              private _utilService : UtilService,
              private _universidadeService : UniversidadeService,
              private _fileService : FileService) { }

  ngOnChanges() {
    this.configureMe();
    this.initEstados();
    this.initUniversidades();
  }

  ngOnInit() {
    this._userService.checkCredentials();
    this.initMe();
    this.initEstados();
    this.initUniversidades();
  }

  initMe() {
    this.configureMe();
  }

  configureMe() {
    if (this.profile.universidade != null) this.profUniversidade = this.profile.universidade.id;

    if (this.profile.endereco != null) this.endereco = this.profile.endereco;
    
    if (this.profile.perfil.personalidade != null) {
      this.personalidade = this.profile.perfil.personalidade;
    }
  }

  initEstados() {
    this.estados = this._utilService.getEstadosBrasileiros();
  }

  initUniversidades() {
    this._universidadeService.getAll().subscribe(data => {
      this.universidades = data;
    });
  }

  changeCep() {
    this.errorCEP = '';
    this._utilService.getAddressByCep(this.endereco.cep).subscribe((data : any) => {
      if (data != null) {
        this.endereco.logradouro = data.logradouro;
        this.endereco.complemento = data.complemento;
        this.endereco.bairro = data.bairro;
        this.endereco.uf = data.uf;
        this.endereco.cidade = data.localidade;
      }
    }, err => {
      this.errorCEP = 'CEP inválido';
    })
  }

  save() {
    if (this.endereco != undefined) {
      this.profile.endereco = this.endereco;
    }
    
    this.sending = true;
    this._userService.update(this.profile).subscribe(data => {
      this.sending = false;
      this.callbackUpdateMessage = 'Seus dados foram atualizados!';
      this.callbackUpdateClass = 'success';
      this.profile = data;
      this.endereco = this.profile.endereco;
    }, err => {
      this.sending = false;
      this.callbackUpdateMessage = 'Ocorreu um erro. Verifique seus dados e tente novamente. Detalhes do erro foram escritos no console do navegador.';
      console.log('Detalhes do erro: ' + err);
      this.callbackUpdateClass = 'danger';
    })
  }

  changeUniversidade() {
    this.universidades.forEach(uni => {
      if (uni.id == this.profUniversidade) {
        this.profile.universidade = uni;
        return;
      }
    });
  }

  compareUniversidade(opt1, opt2)  {
    if (opt1 != undefined && opt2 != undefined) return opt1.id == opt2.id;
    return opt1 == opt2;
  }

  upload(event) {
    if (event.target.files.length > 0) {
      this.fotoPerfil = event.target.files[0];
      this._fileService.upload(this.fotoPerfil).subscribe((data:any) => {
        this.profile.fotoUrl = data.filename;
      })
    }
  }
}
