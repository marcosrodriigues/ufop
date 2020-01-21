import { Component, OnInit } from '@angular/core';
import { AdminService } from '../../service/admin.service';

@Component({
  selector: 'app-admin-info-cadastro',
  templateUrl: './admin-info-cadastro.component.html',
  styleUrls: ['./admin-info-cadastro.component.css']
})
export class AdminInfoCadastroComponent implements OnInit {

  state: any = {
    cadastros: 0,
    republicas: 0,
    estudantes: 0,
    estudantes_aprovados: 0,
    estudantes_pendentes: 0,
    estudantes_sem_rep: 0
  }

  constructor(private _admin : AdminService) { }

  ngOnInit() {
    this._admin.initState().subscribe(data => {
      this.state = data;
    })
  }

}
