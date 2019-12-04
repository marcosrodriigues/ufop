import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { RepublicaService } from 'src/app/service/republica.service';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-republic-detail',
  templateUrl: './republic-detail.component.html',
  styleUrls: ['./republic-detail.component.css']
})
export class RepublicDetailComponent implements OnInit {

  rep: any = { perfil: null }
  me: any = { }
  id: any = 0;

  constructor(private router: ActivatedRoute, private _repService : RepublicaService,
    private _userService: UserService) { 
    this.router.paramMap.subscribe(params => {
      this.id = params.get("id");
    })
  }

  ngOnInit() {
      this._userService.me().subscribe(data => {
        this.me = data;
        if (this.me == null) this.me = {};
      }, err => {
        this.me = {};
      });

      this.initRep();
  }

  initRep() {
    this._repService.findOne(this.id).subscribe(data => {
      this.rep = data;
      if (this.rep.image == null || this.rep.image == '') {
        this.rep.image = 'assets/img/default-user.png';
      }
    });
  }
}
