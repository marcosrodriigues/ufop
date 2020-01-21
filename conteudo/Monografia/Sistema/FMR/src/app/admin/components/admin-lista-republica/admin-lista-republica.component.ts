import { Component, OnInit } from '@angular/core';
import { AdminService } from '../../service/admin.service';

@Component({
  selector: 'app-admin-lista-republica',
  templateUrl: './admin-lista-republica.component.html',
  styleUrls: ['./admin-lista-republica.component.css']
})
export class AdminListaRepublicaComponent implements OnInit {

  republicas: any = [] 

  constructor(private _admin : AdminService) { }

  ngOnInit() {
    this._admin.initReps().subscribe(data => {
      this.republicas = data;
    })
  }

}
